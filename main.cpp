#include "mysvg.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MySvg w;
    w.show();

    return a.exec();
}
