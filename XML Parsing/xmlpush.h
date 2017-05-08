#ifndef XMLPUSH_H
#define XMLPUSH_H

#include <iostream>
#include "Markup.h"
#include <vector>
#include "nodeStruct.h"
#include <string>

class XMLPush
{
private:
    XMLPush();

    CMarkup XML;

    std::vector<std::vector<Node> > map;

    std::vector<Node> temp;
public:
    XMLPush(std::string location);

    std::vector<std::vector<Node> > returnMap();


};

#endif // XMLPUSH_H
