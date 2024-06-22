%{
#include <cassert>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <string>
#include "parser_driver.hh"
#include "tiger_parser.hh"
#include "../utils/errors.hh"

#define TIGER_INT_MAX  2147483647  /*  2^31 - 1 */

# undef yywrap
# define yywrap() 1

// The location of the current token
static yy::location loc;
static int comment_depth = 0;
static std::string string_buffer;
%}

%option noyywrap nounput batch debug noinput

lineterminator  \r|\n|\r\n
blank           [ \t\f]
id              [a-zA-Z][_0-9a-zA-Z]*
int             [0-9]+

 /* Declare two start conditions (sub-automate states) to handle
    strings and comments */
%x STRING
%x COMMENT

%{
  /* Each time a pattern is found, set the end cursor to the matched width */
  # define YY_USER_ACTION loc.columns (yyleng);
%}

%%
%{
  /* Before running the lexer, set the initial cursor position */
  loc.step ();
%}

  /* Each time a line ends, increase the cursor line position and reset the
     begin column position */
{lineterminator}+   loc.lines (yyleng); loc.step ();
  /* When a blank is found skip it by updating the begin cursor column position */
{blank}+   loc.step();

 /* Symbols */

":"      return yy::tiger_parser::make_COLON(loc);
","      return yy::tiger_parser::make_COMMA(loc);
";"      return yy::tiger_parser::make_SEMICOLON(loc);
"("      return yy::tiger_parser::make_LPAREN(loc);
")"      return yy::tiger_parser::make_RPAREN(loc);
"{"      return yy::tiger_parser::make_LBRACE(loc);
"}"      return yy::tiger_parser::make_RBRACE(loc);
"+"      return yy::tiger_parser::make_PLUS(loc);
"-"      return yy::tiger_parser::make_MINUS(loc);
"*"      return yy::tiger_parser::make_TIMES(loc);
"/"      return yy::tiger_parser::make_DIVIDE(loc);
"="      return yy::tiger_parser::make_EQ(loc);
"<>"     return yy::tiger_parser::make_NEQ(loc);
"<"      return yy::tiger_parser::make_LT(loc);
"<="     return yy::tiger_parser::make_LE(loc);
">"      return yy::tiger_parser::make_GT(loc);
">="     return yy::tiger_parser::make_GE(loc);
"&"      return yy::tiger_parser::make_AND(loc);
"|"      return yy::tiger_parser::make_OR(loc);
":="     return yy::tiger_parser::make_ASSIGN(loc);

 /* Keywords */

else     return yy::tiger_parser::make_ELSE(loc);
while    return yy::tiger_parser::make_WHILE(loc);
for      return yy::tiger_parser::make_FOR(loc);
to       return yy::tiger_parser::make_TO (loc);
do       return yy::tiger_parser::make_DO(loc);
let      return yy::tiger_parser::make_LET(loc);
in       return yy::tiger_parser::make_IN(loc);
end      return yy::tiger_parser::make_END(loc);
break    return yy::tiger_parser::make_BREAK(loc);
function return yy::tiger_parser::make_FUNCTION(loc);
var      return yy::tiger_parser::make_VAR(loc);
if       return yy::tiger_parser::make_IF(loc);
then     return yy::tiger_parser::make_THEN(loc);
else     return yy::tiger_parser::make_ELSE(loc);

 /* Identifiers */
{id}       return yy::tiger_parser::make_ID(Symbol(yytext), loc);

 /* Integers */
{int} {
    if (yytext[0] == '0' && yytext[1] != '\0') {
        utils::error(loc, "leading zeros are not allowed");
    }

    long long int value = std::strtoll(yytext, nullptr, 10);
    if (value > TIGER_INT_MAX) {
        utils::error(loc, "integer constant too large");
    }
    return yy::tiger_parser::make_INT(value, loc);
}


 /* Strings */
\" {BEGIN(STRING); string_buffer.clear();}

<STRING>{
    /* \" and \\ */
    "\\\""           {string_buffer.push_back('"');}
    "\\\\"           {string_buffer.push_back('\\');}

    /* C escape characters */
    \\[aA]           {string_buffer.push_back('\a');}
    \\[bB]           {string_buffer.push_back('\b');}
    \\[tT]           {string_buffer.push_back('\t');}
    \\[nN]           {string_buffer.push_back('\n');}
    \\[vV]           {string_buffer.push_back('\v');}
    \\[fF]           {string_buffer.push_back('\f');}
    \\[rR]           {string_buffer.push_back('\r');}

    <<EOF>> | {lineterminator} utils::error (loc, "unterminated string");

    /* end of string */
    "\"" {
        BEGIN(INITIAL);
        return yy::tiger_parser::make_STRING(Symbol(string_buffer), loc);
    }

    "\\" utils::error (loc, "unescaping backslash");

    /* All other characters are accepted */
    . {string_buffer.push_back(yytext[0]);}
}

 /* Comments */

"/*"     {comment_depth = 1; BEGIN(COMMENT);}
<COMMENT>{
   /* Increase cursor line position for each new line */
   {lineterminator}+   loc.lines (yyleng); loc.step ();

    "/*" {comment_depth++;}
    "*/" {comment_depth--; if (comment_depth == 0) BEGIN(INITIAL);}
    <<EOF>> utils::error (loc, "unterminated comment");
    . {}
}

 /* End-of-file marker */
<<EOF>>    return yy::tiger_parser::make_EOF(loc);

 /* Catch-all rule that triggers an error */
.          utils::error (loc, "invalid character");

%%

void ParserDriver::lex_begin ()
{
  yy_flex_debug = trace_lexer;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    utils::error("cannot open " + file + ": " + strerror(errno));
}

void ParserDriver::lex_end ()
{
  fclose (yyin);
}
