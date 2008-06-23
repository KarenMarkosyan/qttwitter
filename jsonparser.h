#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <datastructure.h>

class jsonParser
{
public:
        jsonParser();

//         ~jsonParser();

virtual dataStructure  parseObjectOnPosition ( const QString &content ,int requiredObjectPosition ) = 0;//for parsing single object

virtual QList <dataStructure > parseAllObjects ( const QString &content,int numberOfObjects ) = 0;//for parsing a list objects

private:
        QList <dataStructure> parsedJsonOutput;

        dataStructure dataStorage;

        QScriptEngine myEngine;

};


#endif
