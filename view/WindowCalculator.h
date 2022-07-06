#ifndef WINDOWCALCULATOR_H
#define WINDOWCALCULATOR_H

#include <QWidget>
#include <QLabel>
#include "../controller/HandleCalculator.h"

class QPushButton;
class WindowCalculator : public QWidget {
Q_OBJECT
public:
    HandleCalculator calculatorControl;
    explicit WindowCalculator(QWidget *parent = 0);

private:

    long long int firstExpression = 0;
    long long int secondExpression = 0;
    long long int lastResult = 0;
    bool havePreviousResult = false;
    bool beforeOperator = true;
    unsigned short int operationValue = 0;

    // Tela
    QLabel *tela;

    // Numbers
    QPushButton *numberZero;
    QPushButton *numberOne;
    QPushButton *numberTwo;
    QPushButton *numberThree;
    QPushButton *numberFour;
    QPushButton *numberFive;
    QPushButton *numberSix;
    QPushButton *numberSeven;
    QPushButton *numberEight;
    QPushButton *numberNine;

    // Operators
    QPushButton *sumButton;
    QPushButton *subtractionButton;
    QPushButton *multiplicationButton;
    QPushButton *divisionButton;
    QPushButton *equalsButton;

    // Reset
    QPushButton *cleanButton;


public slots:
    void setNumber(int numberSelection);
    void setTextLabel();
    void setOperator( int operationNumber );
    void clearValues();

signals:
};



#endif //WINDOWCALCULATOR_H
