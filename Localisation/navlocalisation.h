#ifndef NAVLOCALISATION_H
#define NAVLOCALISATION_H

#include <vector>
#include "nodeStruct.h"
#include <math.h>

class NavLocalisation
{
public:
    NavLocalisation(double xLocalised, double yLocalised);
    int findNode(std::vector<Node> &nodeList);

private:
    NavLocalisation();

    double _xPoint;
    double _yPoint;

    double distance(double x, double y, Node &pos);

};

#endif // NAVLOCALISATION_H
