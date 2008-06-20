#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
//
class dataStructure{};//the base class of any json data Structure
class twitterDataStructure : public dataStructure {};
class panoramioDataStructure : public dataStructure {};
//
class jsonParser
{
public:
        jsonParser();

        ~jsonParser();

// virtual dataStructure parseObjectOnPosition ( const QString &content ,int requiredObjectPosition );//for parsing single object
//
// virtual QList <dataStructure > parseAllObjects ( const QString &content,int numberOfObjects );//for parsing a list objects
//
private:
        QList <panoramioDataStructure> parsedJsonOutput;

        panoramioDataStructure dataStorage;

        QScriptEngine myEngine;

};


#endif
