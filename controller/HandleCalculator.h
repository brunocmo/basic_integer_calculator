#ifndef HANDLECALCULATOR_H
#define HANDLECALCULATOR_H

#include <bitset>
#include "../model/Calculator.h"

class HandleCalculator {

public:

    Calculator *calculator;

    int lastOperator;
    enum {
        EQUALS,
        SUM,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION
    };

    HandleCalculator();
    ~HandleCalculator();

    long int handleResult(
            unsigned short int operationSignal,
            long int firstOperator,
            long int secondOperator
    );

    void clearAll() const;

};
#endif //HANDLECALCULATOR_H
