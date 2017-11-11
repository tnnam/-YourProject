#include "yourxmlparsingobject.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YourXMLParsingObject w;
    w.show();

    return a.exec();
}
