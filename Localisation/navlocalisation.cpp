#include "navlocalisation.h"

NavLocalisation::NavLocalisation(double xLocalised, double yLocalised)
{
    _xPoint = xLocalised;
    _yPoint = yLocalised;
}

int NavLocalisation::findNode(std::vector<Node> &nodeList)
{
    //int halfPos = nodeList.size()/2;

    int closeID = 0;

    double minDist = distance(_xPoint,_yPoint, nodeList.at(0));


    for (int i = 1; i < nodeList.size(); i++)
    {
        double currentDist = distance(_xPoint,_yPoint, nodeList.at(i));

        if(currentDist < minDist)
        {
            minDist = currentDist;
            closeID = i;
        }
    }

    return closeID;
}

NavLocalisation::NavLocalisation()
{
}

double NavLocalisation::distance(double x, double y, Node &pos)
{
    double dist;

    dist = sqrt(pow((x - pos.x),2) + pow((y - pos.y),2));

    return dist;


}
