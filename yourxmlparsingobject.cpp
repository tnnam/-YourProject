#include "yourxmlparsingobject.h"
#include "ui_yourxmlparsingobject.h"
#include <QMessageBox>

struct GlobalVarADT{
    QString ID;
    QString text;
};
GlobalVarADT globalVar;

struct Question{
    int questionID;
    QString questionText;
    QString answerText;
};
QList<Question> listQ;

void  YourXMLParsingObject::yourXMLParsingMethod(QString filePath){
    QFile *file = new QFile(filePath);
    
    if(!file->open(QFile::ReadOnly | QFile::Text)){
        return;
    }

    QXmlStreamReader xmlReader(file);
    
    while(!xmlReader.atEnd() && !xmlReader.hasError()){
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if(token == QXmlStreamReader::StartDocument){
            continue;
        }

        if(token == QXmlStreamReader::StartElement){
            if(xmlReader.name() == "GlobalVar"){
                globalVar.ID = xmlReader.attributes().value("ID").toString();
                xmlReader.readNext();
                globalVar.text = xmlReader.text().toString();
            }

            if(xmlReader.name() == "QuestionSet"){
                continue;
            }
            if(xmlReader.name() == "Question"){
                this->parseQuestion(xmlReader);
            }
        }
    }
}

void YourXMLParsingObject::parseQuestion(QXmlStreamReader &xmlReader){
    if(xmlReader.tokenType() != QXmlStreamReader::StartElement
            && xmlReader.name() != "Question"){
            QMessageBox::warning(this, "..", "Called XML parseQuestionElement without a question Element in the XML stream!");
         return;
    }

    Question newQuestion;
    newQuestion.questionID = xmlReader.attributes().value("ID").toString().toInt();
    xmlReader.readNext();

    while(!(xmlReader.tokenType()  == QXmlStreamReader::EndElement
            && xmlReader.name() == "Question")){
        if(xmlReader.tokenType() == QXmlStreamReader::StartElement){
            if(xmlReader.name() == "Text"){
                xmlReader.readNext();
                newQuestion.questionText = xmlReader.text().toString();
            }

            if(xmlReader.name() == "Answer"){
                xmlReader.readNext();
                newQuestion.answerText = xmlReader.text().toString();
            }
        }
        xmlReader.readNext();
    }
    listQ.append(newQuestion);
    return;
}

YourXMLParsingObject::YourXMLParsingObject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::YourXMLParsingObject)
{
    ui->setupUi(this);
    yourXMLParsingMethod("C:/Users/hp/Desktop/DemoXml2.xml");

    //ui->textBrowser->setText(globalVar.ID);
}

YourXMLParsingObject::~YourXMLParsingObject()
{
    delete ui;
}
