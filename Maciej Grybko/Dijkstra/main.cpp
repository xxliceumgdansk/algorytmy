#include<iostream>

using namespace std;
int main()
{
    //MOJE init
    int vertexes, edges;
    int beginningVertex, endingVertex;

    cin >> vertexes >> edges;

    //MOJE edge
    int beginningOfEdge[edges];
    int endOfEdge[edges];
    int CostOfEdge[edges+1];//ostatnia komorka, to //MOJE TODO czemu z duzej litery?!!!!!!!!!
    //edge

    for(int i=0; i<edges; i++)
    {
        cin >> beginningOfEdge[i] >> endOfEdge[i] >> CostOfEdge[i];
    }
    cin >> beginningVertex >> endingVertex;

    //MOJE vertex
    int minCost[vertexes];
    int predecessor[vertexes];
    bool checkedVertexes[vertexes];
    //vertex

    int actualVertex = beginningVertex-1;
    int adjacentVertexes[edges][vertexes]; //neighbours

    for(int j=0; j<vertexes; j++)
    {
        for(int i=0; i<edges; i++)
        {
            adjacentVertexes[i][j]=-1; //przypisanie liczby ujemnej kazdemu sasiadowi kazdego wierzcholka sluzy odroznieniu sasiada, ktory istnieje, od tego, ktory nie istnieje
        }
    }

    for(int i=0; i<vertexes; i++)
    {
        minCost[i]=2147483647; //MOJE infinity
        predecessor[i]=-1;
        checkedVertexes[i]=false;
    }

    CostOfEdge[edges+1]=2147483647; //MOJE TODO chyba wywalic bo ma oznaczac koszt od poczatku do konca

    //finding neighbours
    for(int j=0; j<vertexes; j++)//znajdowanie sasiadow kazdego wierzcholka //MOJE TODO powinno byc na odwrot bo czytelniej jest szukac wierzcholka dla krawedzi, nie na odwrot
    {
        for(int i=0; i<edges; i++)
        {
            if(beginningOfEdge[i]==j)
                adjacentVertexes[i][j]=endOfEdge[i]-1; //jezeli poczatek krawedzi i jest wierzcholkiem j, to jego sasiadem jest koniec krawedzi i
        }
    }
    //finding neighbours
    //init

    cout << "zainicjalizowano!\n";
    for(int j=0; j<vertexes; j++)
    {
        for(int i=0; i<edges; i++)
        {
            if(checkedVertexes[endOfEdge[i]-1]==false && CostOfEdge[i]<CostOfEdge[actualVertex]) //MOJE odjalem 1 od endOfEdge[i] bo jest on w cin podane jako liczba liczac od 1, a tablica checkedVertexes jest od 0
            {
                actualVertex=endOfEdge[i]-1;
            }
        }

        for(int i=0; i<edges; i++)
        {

            if(minCost[adjacentVertexes[i][actualVertex]] > minCost[actualVertex] + CostOfEdge[actualVertex])
            {
                minCost[actualVertex] = minCost[j] + CostOfEdge[i];
                predecessor[adjacentVertexes[i][actualVertex]] = actualVertex;
                break;
            }
            //actualVertex=edges+1;//sluzy do tego, zebysmy przez przypadek nie nadali ponownie (innej) wartosci minCost - nie wiem, czy to w ogole jest potrzebne
        }
        checkedVertexes[endOfEdge[actualVertex]]=true; // odjalem 1 (patrz linijka 67 czemu)
    }

    cout << "done!\n";
    cout << minCost[endingVertex];
    /*for(int i=0; i<edges; i++) cout <<  minCost[i];
    cout << endl;
    for(int i=0; i<edges; i++) cout <<  predecessor[i];*/

    return 0;
}
