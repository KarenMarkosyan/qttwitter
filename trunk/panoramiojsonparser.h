//
// C++ Interface: panoramiojsonparser
//
// Description: 
//
//
// Author: Shashank Singh <shashank.personal@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PANORAMIOJSONPARSER_H
#define PANORAMIOJSONPARSER_H

#include <jsonparser.h>


/**this will include all the code needed to parse output from panoramio

	@author Shashank Singh <shashank.personal@gmail.com>
*/
class panoramioJsonParser : public jsonParser
{
public:
    panoramioJsonParser();

    ~panoramioJsonParser();
    QList< dataStructure > parseAllObjects(const QString& content, int numberOfObjects);
    dataStructure  parseObjectOnPosition(const QString& content, int requiredObjectPosition);

};

#endif
