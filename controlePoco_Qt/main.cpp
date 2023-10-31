#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle("Controle do Poço");
    w.setFixedSize(340, 240);
    w.show();

    return a.exec();
}
