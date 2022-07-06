#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <fstream>
#include <iostream>

class Calculator {

private:
    long int result;
    long int firstOperator;
    long int secondOperator;
    std::string expressionLog;
public:

    Calculator();
    ~Calculator();

    void sum();

    void subtraction();

    void multiplication();

    void division();

    long int getResult() const;

    void setResult(long int result);

    long int getFirstOperator() const;

    void setFirstOperator(long int firstOperator);

    long int getSecondOperator() const;

    void setSecondOperator(long int secondOperator);

    const std::string &getExpressionLog() const;

    void setExpressionLog(const std::string &expressionLog);

    void printLog() const;

    void setValuesToString(char operatorSymbol);

};


#endif //CALCULATOR_H
