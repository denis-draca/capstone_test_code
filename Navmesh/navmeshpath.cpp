#include "navmeshpath.h"

NavMeshPath::NavMeshPath(std::vector<std::vector<Node> > &mapData)
{
    _map = mapData;
}

std::vector<Waypoint> NavMeshPath::Navigate(Node start_point, Node Goal)
{
    bool pathFound = false;
    std::vector<Node> openList;
    std::vector<Node> closedList;

    openList.push_back(start_point);
    _tempWaypoints.push_back(start_point);


    while(!pathFound && !openList.empty())
    {
        closedList.push_back(openList.back());
        openList.pop_back();

        if (closedList.back().ID == Goal.ID)
        {
            pathFound = true;
            break;
        }


        for (int i = 0; i < _map[openList.back().ID].size(); i++)
        {
            _map[closedList.back().ID][i].cost = distance(closedList.back(),_map[closedList.back().ID][i]) + distance(_map[closedList.back().ID][i],Goal);

            openList.push_back(_map[closedList.back().ID][i]);
        }

       descendingOrder(openList);

       _tempWaypoints.push_back(openList.back());

    }
}

NavMeshPath::NavMeshPath()
{
}

double NavMeshPath::distance(Node &point1, Node &point2)
{
    double distance;

    distance = sqrt(pow((point1.x - point2.x),2) + pow((point1.y - point2.y),2));

    return distance;
}

void NavMeshPath::descendingOrder(std::vector<Node> &tempList)
{
//    /*
//     *
//     *      Find an efficient sorting algorithm
//     *
//     */
//    for (int i = 0; i < tempList.size(); i++)
//    {
//        continue;
//    }

    //std::vector<Node> holder;
    for (int x = 0; x< tempList.size() - 1; x++)
    {
        Node max = tempList.at(x);
        int pos = x;

        for (int i = x + 1; i< tempList.size(); i++)
        {
            if(tempList.at(i).cost > max.cost)
            {
                max = tempList.at(i);
                pos = i;

            }
        }

        Node temp = tempList.at(x);
        tempList.at(x) = tempList.at(pos);
        tempList.at(pos) = temp;
    }
}


