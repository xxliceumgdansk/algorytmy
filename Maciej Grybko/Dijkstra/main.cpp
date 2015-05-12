#include<iostream>

using namespace std;

int main()
{
int vertexes, edges;
cin >> vertexes >> edges;
int beginningOfEdge[edges];
int endOfEdge[edges];
int CostOfEdge[edges+1];//ostatnia komorka, to
int beginningVertex, endingVertex;

for(int i=0; i<edges; i++)
{
    cin >> beginningOfEdge[i] >> endOfEdge[i] >> CostOfEdge[i];
}
cin >> beginningVertex >> endingVertex;

int minCost[vertexes];
int predecessor[vertexes];
bool checkedVertexes[vertexes];
int actualVertex = beginningVertex;
//int actualCosts[];
int adjacentVertexes[edges][vertexes];
//int neighbourNumber=0;

for(int j=0; j<vertexes; j++)
{
    for(int i=0; i<edges; i++)
    {
        adjacentVertexes[i][j]=-1; //przypisanie liczby ujemnej kazdemu sasiadowi kazdego wierzcholka sluzy odroznieniu sasiada, ktory istnieje, od tego, ktory nie istnieje
    }
}

for(int i=0; i<vertexes; i++)
{
    minCost[i]=2147483647;
    predecessor[i]=-1;
    checkedVertexes[i]=false;
}

CostOfEdge[edges+1]=2147483647;


for(int j=0; j<vertexes; j++)//znajdowanie sasiadow kazdego wierzcholka
{
    for(int i=0; i<edges; i++)
    {
        if(beginningOfEdge[i]==j)adjacentVertexes[i][j]=endOfEdge[i]; //jezeli poczatek krawedzi i jest wierzcholkiem j, to jego sasiadem jest koniec krawedzi i
    }
}
for(int j=0; j<vertexes; j++)
{
    for(int i=0; i<edges; i++)
    {
        if(checkedVertexes[endOfEdge[i]]==false&&CostOfEdge[i]<CostOfEdge[actualVertex])
        {
            actualVertex=endOfEdge[i];
        }
    }
    for(int i=0; i<edges; i++)
    {

        if(minCost[adjacentVertexes[i][actualVertex]] > minCost[actualVertex] + CostOfEdge[actualVertex])
        {
            minCost[actualVertex] = minCost[j] + CostOfEdge[i];
            predecessor[adjacentVertexes[i][actualVertex]] = actualVertex;
        }
        actualVertex=edges+1;//sluzy do tego, zebysmy przez przypadek nie nadali ponownie (innej) wartosci minCost - nie wiem, czy to w ogole jest potrzebne
    }
    checkedVertexes[endOfEdge[actualVertex]]=true;
}

for(int i=0; i<edges; i++) cout <<  minCost[i];
cout << endl;
for(int i=0; i<edges; i++) cout <<  predecessor[i];

return 0;
}
