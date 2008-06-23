//
// C++ Interface: twitterjsonparser
//
// Description:
//
//
// Author: Shashank Singh <shashank.personal@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef TWITTERJSONPARSER_H
#define TWITTERJSONPARSER_H
#include <QString>
#include <jsonparser.h>

/**
    @author Shashank Singh <shashank.personal@gmail.com>
*/
class twitterJsonParser : public jsonParser
{
public:
        twitterJsonParser();

        ~twitterJsonParser();

        QList< dataStructure > parseAllObjects(const QString& content, int numberOfObjects);
        dataStructure  parseObjectOnPosition(const QString& content, int requiredObjectPosition);

};

#endif
