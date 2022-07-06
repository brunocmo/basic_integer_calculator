#include "Calculator.h"

Calculator::Calculator() {
    result = 0;
    firstOperator = 0;
    secondOperator = 0;
}

Calculator::~Calculator() = default;

void Calculator::sum() {
    setResult(getFirstOperator() + getSecondOperator());
    setValuesToString('+');
}

void Calculator::subtraction() {
    setResult(getFirstOperator() - getSecondOperator());
    setValuesToString('-');
}

void Calculator::multiplication() {
    setResult(getFirstOperator() * getSecondOperator());
    setValuesToString('*');
}

void Calculator::division() {
    setResult(getFirstOperator() / getSecondOperator());
    setValuesToString('/');
}

long int Calculator::getResult() const {
    return result;
}

void Calculator::setResult(long int result) {
    Calculator::result = result;
}

long int Calculator::getFirstOperator() const {
    return firstOperator;
}

void Calculator::setFirstOperator(long int firstOperator) {
    Calculator::firstOperator = firstOperator;
}

long int Calculator::getSecondOperator() const {
    return secondOperator;
}

void Calculator::setSecondOperator(long int secondOperator) {
    Calculator::secondOperator = secondOperator;
}



const std::string &Calculator::getExpressionLog() const {
    return expressionLog;
}

void Calculator::setExpressionLog(const std::string &expressionLog) {
    Calculator::expressionLog = expressionLog;
}

void Calculator::setValuesToString(char operatorSymbol) {
    setExpressionLog(
            std::to_string(getFirstOperator()) +
            operatorSymbol +
            std::to_string(getSecondOperator()) +
            " = " +
            std::to_string(getResult())
    );

    printLog();
}

void Calculator::printLog() const {

    std::ofstream operationsLog ("../log/operationsLog.txt", std::ios_base::app);

    std::cout << "teste :" << getExpressionLog() << '\n';

    if (operationsLog.is_open()) {
        operationsLog << getExpressionLog() << '\n';
        operationsLog.close();
    } else std::cout << "Error, cannot open file" << '\n';
}
