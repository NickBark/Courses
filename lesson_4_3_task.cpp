#include <iostream>

using namespace std;

struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

struct Number : Expression {
    Number(double value) : value(value) {}

    virtual double evaluate() const override { return value; }

  private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих
      операциям, которые вам нужно реализовать.
     */
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right) {}

    ~BinaryOperation() {
        delete right;
        delete left;
    }

    virtual double evaluate() const override;

  private:
    Expression const* left;
    char op;
    Expression const* right;
};

double BinaryOperation::evaluate() const {
    double res = 0;
    if (this->op == '+') {
        res = left->evaluate() + right->evaluate();
    } else if (this->op == '-') {
        res = left->evaluate() - right->evaluate();
    } else if (this->op == '*') {
        res = left->evaluate() * right->evaluate();
    } else if (this->op == '/' && (right->evaluate() != 0)) {
        res = left->evaluate() / right->evaluate();
    } else {
        cout << "ERROR" << endl;
    }
    return res;
}

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    cout << expr->evaluate() << endl;   

    delete expr;

    return 0;
}