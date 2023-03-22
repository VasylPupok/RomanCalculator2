#ifndef VISITORS_H
#define VISITORS_H

#include "Calculator.h"

// some standard visitors

class AddVisitor : public Calculator::OperationVisitor {
public:
    AddVisitor() = default;

    int visit(const Calculator& v, int a, int b) const override {
        return a + b;
    }
};

class SubtractVisitor : public Calculator::OperationVisitor {
public:
    SubtractVisitor() = default;

    int visit(const Calculator& v, int a, int b) const override {
        return a - b;
    }
};

class MultiplyVisitor : public Calculator::OperationVisitor {
public:
    MultiplyVisitor() = default;

    int visit(const Calculator& v, int a, int b) const override {
        return a * b;
    }
};

class DivideVisitor : public Calculator::OperationVisitor {
public:
    DivideVisitor() = default;

    int visit(const Calculator& v, int a, int b) const override {
        return a / b;
    }
};

class PowerVisitor : public Calculator::OperationVisitor {
public:
    PowerVisitor() = default;

    int visit(const Calculator& v, int a, int b) const override;
};

#endif // VISITORS_H
