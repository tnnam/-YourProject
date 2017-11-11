#ifndef YOURXMLPARSINGOBJECT_H
#define YOURXMLPARSINGOBJECT_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>
#include <QList>
#include <QXmlStreamReader>

namespace Ui {
class YourXMLParsingObject;
}

class YourXMLParsingObject : public QMainWindow
{
    Q_OBJECT

public:
    explicit YourXMLParsingObject(QWidget *parent = 0);
    ~YourXMLParsingObject();

private:
    Ui::YourXMLParsingObject *ui;
    QString xmlFilePath = "C:/Users/hp/Desktop/DemoXml2.xml";
    void yourXMLParsingMethod(QString);
    void parseQuestion(QXmlStreamReader &);
};

#endif // YOURXMLPARSINGOBJECT_H
