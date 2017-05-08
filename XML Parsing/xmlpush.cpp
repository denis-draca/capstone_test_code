#include "xmlpush.h"

XMLPush::XMLPush(std::string location)
{
    XML.Load(location);
}

std::vector<std::vector<Node> > XMLPush::returnMap()
{
    bool mapDone = false;

    while (!mapDone)
    {
        XML.FindElem();
        XML.IntoElem();
        //Connect Nodes

        XML.FindElem();
        XML.IntoElem();
        //Node

        XML.FindElem();

        if (XML.GetData() == "FOUND")
        {
            mapDone = true;
            break;
        }

        while(XML.GetData() != "done")
        {
            Node node;

            node.ID = std::stoi(XML.GetData());

            XML.FindElem();

            node.x = std::stod(XML.GetData());

            XML.FindElem();
            node.y = std::stod(XML.GetData());

            temp.push_back(node);

            XML.OutOfElem();
            //back to connect Nodes
            XML.FindElem();
            XML.IntoElem();
            //into next node

            XML.FindElem();

        }

        map.push_back(temp);
        temp.clear();

        XML.OutOfElem();
        XML.OutOfElem();
    }

    return map;
}

