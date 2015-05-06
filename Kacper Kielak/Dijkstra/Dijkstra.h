#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Structures.cpp"

class Dijkstra
{
   public:
        Dijkstra(Vertice* vertices, int verticesNumber, int start);
        void writeTravelCost(int finish);
        ~Dijkstra();
    private:
        int verticesNumber;
        Vertice* checkedVertices;
        Vertice* uncheckedVertices;
        int start;
        int numberOfCheckedVertices;
        void countTravelCosts();
        void checkClosestVertice();
        bool isEnd();
        int getOrdinalOfClosestVertice();

};

#endif
