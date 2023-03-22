#pragma once

class Calculator {

public:

	Calculator();
	~Calculator();

	int add(int a, int b) const;

	int subtract(int a, int b) const;

	int divide(int a, int b) const;

	int multiply(int a, int b) const;

    class OperationVisitor {
        //friend class Calculator;
    public:

        virtual ~OperationVisitor() = default;

        virtual int visit(const Calculator& v, int a, int b) const = 0;
    };

    int acceptVisitor(const OperationVisitor* v, int a, int b) const;

};
