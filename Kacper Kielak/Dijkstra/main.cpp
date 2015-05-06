#include "Dijkstra.cpp"
#include <iostream>


Vertice* initializeVertices(int verticesNumber, int edgesNumber)
{
    Vertice *vertices = new Vertice[verticesNumber];
    for(int i=0; i<verticesNumber; i++)
        vertices[i].reset();

    for(int i=0; i<edgesNumber; i++)
    {
        Neighbor tempNeighbor1, tempNeighbor2;
        int travelCost, vertice1, vertice2;
        std::cin >> vertice1 >> vertice2 >> travelCost;
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
    std::cin >> testsNumber;
    int verticesNumber, edgesNumber;
    Vertice* vertices;
    int start, finish;
    for(int i=0; i<testsNumber; i++)
    {
        std::cin >> verticesNumber >> edgesNumber;
        vertices = initializeVertices(verticesNumber, edgesNumber);
        std::cin >> start >> finish;
        start--; //
        finish--;// coumputer counts from 0, not from 1
        vertices[start].travelCost = 0;
        Dijkstra dijkstra(vertices, verticesNumber, start);
        dijkstra.writeTravelCost(finish);
    }
    delete vertices;
    return 0;
}
