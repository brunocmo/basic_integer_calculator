#include "HandleCalculator.h"

HandleCalculator::HandleCalculator() {

    calculator = new Calculator();
    lastOperator = 0;

}

HandleCalculator::~HandleCalculator() = default;

long int HandleCalculator::handleResult(
        unsigned short int operationSignal,
        long int firstOperator,
        long int secondOperator
        ) {

        if (operationSignal != EQUALS) {
            calculator->setFirstOperator(firstOperator);
            calculator->setSecondOperator(secondOperator);
            lastOperator = operationSignal;
        }

        switch(operationSignal) {
            case SUM :
                calculator->sum();
                lastOperator = SUM;
                break;
            case SUBTRACTION :
                calculator->subtraction();
                lastOperator = SUBTRACTION;
                break;
            case MULTIPLICATION :
                calculator->multiplication();
                lastOperator = MULTIPLICATION; break;
            case DIVISION :
                calculator->division();
                lastOperator = DIVISION; break;
            case EQUALS:
                calculator->setResult(handleResult(lastOperator, calculator->getResult(), calculator->getSecondOperator()));
                break;
            default:
                break;
        }

        return calculator->getResult();

}

void HandleCalculator::clearAll() const {
    calculator->setFirstOperator(0);
    calculator->setSecondOperator(0);
    calculator->setResult(0);
}
