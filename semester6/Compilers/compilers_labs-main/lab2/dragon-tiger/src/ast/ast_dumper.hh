#ifndef AST_DUMPER_HH
#define AST_DUMPER_HH

#include <ostream>

#include "nodes.hh"

namespace ast {

class ASTDumper : public ConstASTVisitor {
  std::ostream *ostream;
  bool verbose;
  unsigned indent_level = 0;
  void inc() { indent_level++; }
  void inl() {
    inc();
    nl();
  };
  void dec() { indent_level--; }
  void dnl() {
    dec();
    nl();
  };

public:
  ASTDumper(std::ostream *_ostream, bool _verbose)
      : ostream(_ostream), verbose(_verbose) {}
  void nl() {
    *ostream << std::endl;
    for (unsigned i = 0; i < indent_level; i++)
      *ostream << "  ";
  };
  virtual void visit(const IntegerLiteral &);
  virtual void visit(const StringLiteral &);
  virtual void visit(const BinaryOperator &);
  virtual void visit(const Sequence &);
  virtual void visit(const Let &);
  virtual void visit(const Identifier &);
  virtual void visit(const IfThenElse &);
  virtual void visit(const VarDecl &);
  virtual void visit(const FunDecl &);
  virtual void visit(const FunCall &);
  virtual void visit(const WhileLoop &);
  virtual void visit(const ForLoop &);
  virtual void visit(const Break &);
  virtual void visit(const Assign &);
};

} // namespace ast

#endif // _AST_DUMPER_HH
