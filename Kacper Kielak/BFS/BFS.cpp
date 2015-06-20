#include "BFS.h"

BreadthFirstSearch::BreadthFirstSearch(vector<node*> _graph, int _numberOfNodes)
{
    graph = _graph;
    numberOfNodes = _numberOfNodes;
}

vector<int> BreadthFirstSearch::SearchGraph() {
    vector<int> resultList;

    vector<int> checkingNodes(1, 0);
    while(checkingNodes.size()!=0)
    {
        addVectors<int>(resultList, checkingNodes);
        checkingNodes = getNeighboursAndCheck(checkingNodes);
    }

    return resultList;
}

bool BreadthFirstSearch::Bipartite() {
    return false;
}

vector<int> BreadthFirstSearch::getNeighboursAndCheck(vector<int> checkingNodes)
{
    vector<int> neighbours;
    for(int i=0; i<checkingNodes.size(); i++)
    {
        node *currentNode = graph[checkingNodes[i]];
        for(int j=0; (*currentNode).next[j]!=nullptr; j++)
        {
            if(!(*currentNode).isChecked)
            {
                (*currentNode).isChecked = true;
                neighbours.push_back((*currentNode).next[j].number);
            }
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
