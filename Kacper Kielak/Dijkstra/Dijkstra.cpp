
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define UNDEFINED -1
#define INFINITY 2000000000

struct Neighbor
{
    int ordinal;
    int travelCost;
};

struct Vertice
{
    vector<Neighbor> neighbors;
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
        if(this->pathToStart == UNDEFINED &&
        this->travelCost == INFINITY &&
        this->neighbors.empty())
            return true;
    }
};

class Djikstra
{
    public:

        Djikstra(Vertice* vertices, int verticesNumber, int start)
        {
            this->uncheckedVertices = vertices;
            this->checkedVertices = new Vertice[verticesNumber];
            this->verticesNumber = verticesNumber;
            this->start = start;
            this->numberOfCheckedVertices = 0;
            countTravelCosts();
        }

        int getTravelCost(int finish)
        {
            return checkedVertices[finish].travelCost;
        }

        ~Djikstra()
        {
            delete checkedVertices;
        }

    private:
        int verticesNumber;
        Vertice* checkedVertices;
        Vertice* uncheckedVertices;
        int start;
        int numberOfCheckedVertices;

        void countTravelCosts()
        {
            while(!isEnd())
                checkClosestVertice();

            delete []uncheckedVertices;
            return;
        }

        void checkClosestVertice()
        {
            int ordinalOfClosestVertice = getOrdinalOfClosestVertice();
            Vertice closestVertice = uncheckedVertices[ordinalOfClosestVertice];

            for(int i=0; i<closestVertice.neighbors.size(); i++)
            {
                Vertice tempVertice = uncheckedVertices[closestVertice.neighbors[i].ordinal];
                if(!tempVertice.isReseted() && tempVertice.travelCost > closestVertice.travelCost + closestVertice.neighbors[i].travelCost)
                {
                    tempVertice.pathToStart = ordinalOfClosestVertice;
                    tempVertice.travelCost = closestVertice.travelCost + closestVertice.neighbors[i].travelCost;
                }

                uncheckedVertices[closestVertice.neighbors[i].ordinal] = tempVertice;
            }

            checkedVertices[ordinalOfClosestVertice] = closestVertice;
            uncheckedVertices[ordinalOfClosestVertice].reset();
            numberOfCheckedVertices++;

            return;
        }

        bool isEnd()
        {
            if(numberOfCheckedVertices<verticesNumber)
                return false;

            return true;
        }

        int getOrdinalOfClosestVertice()
        {
            int minTravelCost = INFINITY;
            int closestVertice = UNDEFINED;
            for(int i=0; i<verticesNumber; i++)
            {
                if(uncheckedVertices[i].travelCost<minTravelCost)
                {
                    minTravelCost = uncheckedVertices[i].travelCost;
                    closestVertice = i;
                }
            }
            return closestVertice;
        }


};

Vertice* initializeVertices(int verticesNumber, int edgesNumber)
{
    Vertice *vertices = new Vertice[verticesNumber];
    for(int i=0; i<verticesNumber; i++)
        vertices[i].reset();

    for(int i=0; i<edgesNumber; i++)
    {
        Neighbor tempNeighbor1, tempNeighbor2;
        int travelCost, vertice1, vertice2;
        cin >> vertice1 >> vertice2 >> travelCost;
        tempNeighbor1.ordinal = vertice2-1;
        tempNeighbor2.ordinal = vertice1-1;
        tempNeighbor1.travelCost = travelCost;
        tempNeighbor2.travelCost = travelCost;

        vertices[vertice1-1].neighbors.push_back(tempNeighbor1);
        vertices[vertice2-1].neighbors.push_back(tempNeighbor2);
    }
    return vertices;
}

int main()
{
    int testsNumber;
    cin >> testsNumber;
    int verticesNumber, edgesNumber;
    Vertice* vertices;
    int start, finish;
    for(int i=0; i<testsNumber; i++)
    {
        cin >> verticesNumber >> edgesNumber;
        vertices = initializeVertices(verticesNumber, edgesNumber);
        cin >> start >> finish;
        start--; //
        finish--;// coumputer counts from 0, not from 1
        vertices[start].travelCost = 0;
        Djikstra djikstra(vertices, verticesNumber, start);
        cout << djikstra.getTravelCost(finish);
    }
    delete []vertices;
    return 0;
}
