#ifndef COMPILERS_LABS_EVALUATORS_H
#define COMPILERS_LABS_EVALUATORS_H

#include "nodes.hh"
#include "../utils/errors.hh"

namespace ast {
    class ASTEvaluator : public ConstASTIntVisitor {
    public:
        ASTEvaluator() = default;
        ~ASTEvaluator() = default;

        /**
         * Evaluates to its integer value
         * @param lit integer literal
         * @return integer value
         */
        int32_t visit(const IntegerLiteral &integerLiteral) override {
            return integerLiteral.value;
        }

        /**
         * Evaluates to the result between the two operands. For boolean operators 1 is true and 0 is false.
         * @param op binary operator
         * @return integer value
         */
        int32_t visit(const class BinaryOperator &binaryOperator) override {
            int32_t left = binaryOperator.get_left().accept(*this);
            int32_t right = binaryOperator.get_right().accept(*this);
            switch (binaryOperator.op)
            {
                case o_plus:
                    return left + right;
                case o_minus:
                    return left - right;
                case o_times:
                    return left * right;
                case o_divide:
                    return left / right;
                case o_eq:
                    return left == right;
                case o_neq:
                    return left != right;
                case o_lt:
                    return left < right;
                case o_gt:
                    return left > right;
                case o_le:
                    return left <= right;
                case o_ge:
                    return left >= right;
                default:
                    utils::error("Unknown binary operator");
            }
        }

        /**
         * Evaluates the sequence of expressions and returns the value of the last one.
         * @param sequence sequence of expressions
         */
        int32_t visit(const class Sequence & sequence) {
            int32_t result = 0;
            for (const auto &expr : sequence.get_exprs()) {
                result = expr->accept(*this);
            }
            return result;
        }

        /**
         * Evaluates the if-then-else expression and returns the value of the then or else part.
         * @param ifThenElse if-then-else expression
         */
        int32_t visit(const class IfThenElse & ifThenElse) {
            int32_t condition = ifThenElse.get_condition().accept(*this);
            if (condition) {
                return ifThenElse.get_then_part().accept(*this);
            } else {
                return ifThenElse.get_else_part().accept(*this);
            }
        }

        int32_t visit(const class StringLiteral &) {
            utils::error("Cannot evaluate string literals");
        }

        int32_t visit(const class Let &) {
            utils::error("Cannot evaluate let expressions");
        }

        int32_t visit(const class Identifier &) {
            utils::error("Cannot evaluate identifiers");
        }

        int32_t visit(const class VarDecl &) {
            utils::error("Cannot evaluate variable declarations");
        }

        int32_t visit(const class FunDecl &) {
            utils::error("Cannot evaluate function declarations");
        }

        int32_t visit(const class FunCall &) {
            utils::error("Cannot evaluate function calls");
        }

        int32_t visit(const class WhileLoop &) {
            utils::error("Cannot evaluate while loops");
        }

        int32_t visit(const class ForLoop &) {
            utils::error("Cannot evaluate for loops");
        }
        int32_t visit(const class Break &) {
            utils::error("Cannot evaluate break statements");
        }

        int32_t visit(const class Assign &) {
            utils::error("Cannot evaluate assignments");
        }

    private:
        bool verbose_;
    };
}

#endif //COMPILERS_LABS_EVALUATORS_H
