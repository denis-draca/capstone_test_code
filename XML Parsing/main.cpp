#include <iostream>
#include "Markup.h"
#include <unistd.h>
#include "nodeStruct.h"
#include "xmlpush.h"

using namespace std;

int main()
{
    XMLPush xml("/home/denis/Desktop/XML_TEST/xTest2/test2/testNode.xml");

    std::vector<std::vector <Node> > map;

    map = xml.returnMap();

    std::cout<<map.size()<<std::endl;

}

