#ifndef NAVMESHPATH_H
#define NAVMESHPATH_H

#include <vector>
#include "nodeStruct.h"
#include <math.h>

class NavMeshPath
{
public:
    NavMeshPath(std::vector<std::vector<Node> > &mapData);

    std::vector<Waypoint> Navigate(Node start_point, Node Goal);


private:
    NavMeshPath();

    std::vector<Waypoint> _waypoints;
    std::vector<Node> _tempWaypoints;
    std::vector<std::vector<Node> > _map;

    double distance(Node &point1, Node &point2);
    void descendingOrder(std::vector<Node> &tempList);
};

#endif // NAVMESHPATH_H
