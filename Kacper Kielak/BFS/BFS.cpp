#include "BFS.h"

BreadthFirstSearch::BreadthFirstSearch(vector<node*> _graph, int _numberOfNodes)
{
    graph = _graph;
    numberOfNodes = _numberOfNodes;
}

vector<int> BreadthFirstSearch::SearchGraph() {
    vector<int> resultList;

    vector<int> actualNodes(1, 0);
    while(actualNodes.size()!=0)
    {
        addVectors<int>(resultList, actualNodes);
        actualNodes = getNeighbours(actualNodes);
    }

    return resultList;
}

bool BreadthFirstSearch::Bipartite() {
    return false;
}

vector<int> BreadthFirstSearch::getNeighbours(vector<int> checkingNodes)
{
    vector<int> neighbours;
    for(int i=0; i<checkingNodes.size(); i++)
    {
        node *currentNode = graph[checkingNodes[i]];
        vector<int> currentNodeNeighbours = getNeighbours(*currentNode);
        addVectors<int>(neighbours, currentNodeNeighbours);
    }
    return neighbours;
}

vector<int> BreadthFirstSearch::getNeighbours(node &checkingNode)
{
    vector<int> neighbours;
    for(int j=0; checkingNode.next[j]!=nullptr; j++)
    {
        if(!checkingNode.wasVisited)
        {
            checkingNode.wasVisited = true;
            neighbours.push_back(checkingNode.next[j].number);
        }
    }

    return neighbours;
}

template<class T>
void BreadthFirstSearch::addVectors(vector<T> &base, vector<T> adder)
{
    for(int i=0; i<adder.size(); i++)
        base.push_back(adder[i]);
}
