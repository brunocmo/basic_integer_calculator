#include <QApplication>
#include "view/WindowCalculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WindowCalculator window;
    window.show();

    return QApplication::exec();
}
