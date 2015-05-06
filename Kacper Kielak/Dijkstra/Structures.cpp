#include <vector>

#define UNDEFINED -1
#define INFINITY 2000000000


struct Neighbor
{
    int ordinal;
    int travelCost;
};

struct Vertice
{
    std::vector<Neighbor> neighbors;
    int travelCost;//=INFINITY
    int pathToStart;//=UNDEFINED

    void reset()
    {
        this->pathToStart = UNDEFINED;
        this->travelCost = INFINITY;
        this->neighbors.clear();
    }

    bool isReseted()
    {
        if (this->pathToStart == UNDEFINED &&
        this->travelCost == INFINITY &&
        this->neighbors.empty())
            return true;

        return false;
    }
};
