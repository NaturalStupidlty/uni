#include "../ast/nodes.hh"
#include "tiger_parser.hh"
#include <string>

// Tell Flex the lexer's prototype ...
#define YY_DECL yy::tiger_parser::symbol_type yylex(ParserDriver &driver)
// ... and declare it for the parser's sake.
YY_DECL;

class ParserDriver {
public:
  ParserDriver(bool _trace_lexer, bool _trace_parser) :
    trace_lexer(_trace_lexer), trace_parser(_trace_parser) {}
  virtual ~ParserDriver() {};

  // Handling the lexer.
  void lex_begin();
  void lex_end();

  // Whether lexer or parser traces should be generated.
  bool trace_lexer;
  bool trace_parser;

  // The parser produced AST
  Expr *result_ast;

  // Run the parser on file f.
  // Returns true on success.
  bool parse(const std::string &f);

  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  std::string file;
};
