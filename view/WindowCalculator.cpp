#include "WindowCalculator.h"
#include <QPushButton>
#include <QApplication>
#include <QSignalMapper>

WindowCalculator::WindowCalculator(QWidget *parent) :
    QWidget(parent) {
        setWindowTitle(QString("Basic Integer Calculator"));
        setFixedSize(340,170);


        tela = new QLabel("0",this);
        tela->setGeometry(10,10,300,30);
        tela->setAlignment(Qt::AlignRight);


        numberSeven = new QPushButton("7", this);
        numberSeven->setGeometry(10,40,80,30);

        numberEight = new QPushButton("8", this);
        numberEight->setGeometry(90,40,80,30);

        numberNine = new QPushButton("9", this);
        numberNine->setGeometry(170,40,80,30);

        numberFour = new QPushButton("4", this);
        numberFour->setGeometry(10,70,80,30);

        numberFive = new QPushButton("5", this);
        numberFive->setGeometry(90,70,80,30);

        numberSix = new QPushButton("6", this);
        numberSix->setGeometry(170,70,80,30);

        numberOne = new QPushButton("1", this);
        numberOne->setGeometry(10,100,80,30);

        numberTwo = new QPushButton("2", this);
        numberTwo->setGeometry(90,100,80,30);

        numberThree = new QPushButton("3", this);
        numberThree->setGeometry(170,100,80,30);

        cleanButton = new QPushButton("AC", this);
        cleanButton->setGeometry(10,130,80,30);
        cleanButton->setStyleSheet("QPushButton"
                                    "{"
                                    "background-color : darkslategray;"
                                    "font"
                                    "}");

        numberZero = new QPushButton("0", this);
        numberZero->setGeometry(90,130,80,30);

        equalsButton = new QPushButton("=", this);
        equalsButton->setGeometry(170,130,80,30);
        equalsButton->setStyleSheet("QPushButton"
                                    "{"
                                    "background-color : orange;"
                                    "font"
                                    "}");

        sumButton = new QPushButton("+", this);
        sumButton->setGeometry(250, 40, 80, 30);
        sumButton->setStyleSheet("QPushButton"
                                   "{"
                                   "background-color : lightslategray;"
                                   "font"
                                   "}");

        subtractionButton = new QPushButton("-", this);
        subtractionButton->setGeometry(250, 70, 80, 30);
        subtractionButton->setStyleSheet("QPushButton"
                                   "{"
                                   "background-color : lightslategray;"
                                   "font"
                                   "}");

        multiplicationButton = new QPushButton("*", this);
        multiplicationButton->setGeometry(250, 100, 80, 30);
        multiplicationButton->setStyleSheet("QPushButton"
                                   "{"
                                   "background-color : lightslategray;"
                                   "font"
                                   "}");

        divisionButton = new QPushButton("/", this);
        divisionButton->setGeometry(250, 130, 80, 30);
        divisionButton->setStyleSheet("QPushButton"
                                   "{"
                                   "background-color : lightslategray;"
                                   "font"
                                   "}");

        auto* mapeadorNumero = new QSignalMapper (this);
        auto* mapeadorOperador = new QSignalMapper (this);

        connect(numberZero, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberOne, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberTwo, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberThree, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberFour, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberFive, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberSix, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberSeven, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberEight, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));
        connect(numberNine, SIGNAL(clicked()), mapeadorNumero, SLOT( map() ));

        connect(sumButton, SIGNAL(clicked()),  mapeadorOperador, SLOT( map() ));
        connect(subtractionButton, SIGNAL(clicked()),  mapeadorOperador, SLOT( map() ));
        connect(multiplicationButton, SIGNAL(clicked()),  mapeadorOperador, SLOT( map() ));
        connect(divisionButton, SIGNAL(clicked()),  mapeadorOperador, SLOT( map() ));

         mapeadorNumero->setMapping(numberZero, 0);
         mapeadorNumero->setMapping(numberOne, 1);
         mapeadorNumero->setMapping(numberTwo, 2);
         mapeadorNumero->setMapping(numberThree, 3);
         mapeadorNumero->setMapping(numberFour, 4);
         mapeadorNumero->setMapping(numberFive, 5);
         mapeadorNumero->setMapping(numberSix, 6);
         mapeadorNumero->setMapping(numberSeven, 7);
         mapeadorNumero->setMapping(numberEight, 8);
         mapeadorNumero->setMapping(numberNine, 9);

         mapeadorOperador->setMapping(sumButton, 1);
         mapeadorOperador->setMapping(subtractionButton, 2);
         mapeadorOperador->setMapping(multiplicationButton, 3);
         mapeadorOperador->setMapping(divisionButton, 4);

        connect(mapeadorOperador, SIGNAL(mappedInt(int)), this, SLOT(setOperator(int)));
        connect( mapeadorNumero, SIGNAL(mappedInt(int)), this, SLOT(setNumber(int)));
        connect(equalsButton, SIGNAL (clicked()), this, SLOT( setTextLabel() ));
        connect(cleanButton, SIGNAL (clicked()), this, SLOT(clearValues()));
    }

void WindowCalculator::setTextLabel() {

    if(beforeOperator) {
        operationValue = 0;
    }

    long long int resultExpression {calculatorControl.handleResult(
            operationValue,
            firstExpression,
            secondExpression
            )};

    tela->setText( QString::number( resultExpression ));

    lastResult = resultExpression;
    firstExpression = 0;
    secondExpression = 0;
    beforeOperator = true;
    havePreviousResult = true;

}

void WindowCalculator::setNumber(int numberSelection) {
    tela->setText(" ");

    havePreviousResult = false;

    if (beforeOperator) {
        if (firstExpression == 0) {
            firstExpression = numberSelection;
        } else {
            firstExpression *= 10;
            firstExpression += numberSelection;
        }
        tela->setText(QString::number(firstExpression));
    } else {
        if (secondExpression == 0) {
            secondExpression = numberSelection;
        } else {
            secondExpression *= 10;
            secondExpression += numberSelection;
        }
        tela->setText(QString::number(secondExpression));
    }
}

void WindowCalculator::setOperator( int operationNumber ) {
    operationValue = operationNumber;
    if (havePreviousResult) {
        firstExpression = lastResult;
        havePreviousResult = false;
    }
    beforeOperator = false;
    tela->setText(" ");
}

void WindowCalculator::clearValues() {
    firstExpression = 0;
    secondExpression = 0;
    beforeOperator = true;
    havePreviousResult = false;
    lastResult = 0;
    calculatorControl.clearAll();
    tela->setText("0");
}
