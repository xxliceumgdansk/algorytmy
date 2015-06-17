#include "BFS.h"

BreadthFirstSearch::BreadthFirstSearch(vector<node*> _graph, int _numberOfNodes)
{
    graph = _graph;
    numberOfNodes = _numberOfNodes;
}

vector<int> BreadthFirstSearch::SearchGraph() {
    vector<int> resultList;

    int checkedNodes = 0;
    vector<int> checkingNodes(1, 0);
    vector<int> toCheckNodes;
    while(checkedNodes < numberOfNodes)
    {
        for(int i=0; i<checkingNodes.size(); i++)
        {
            node currentNode = *graph[checkingNodes[i]];
            for(int j=0; currentNode.next[j]!=nullptr; j++)
                toCheckNodes.push_back(currentNode.next[j].number);
        }

        addVectors<int>(resultList, checkingNodes);
        checkedNodes += checkingNodes.size();
        checkingNodes = toCheckNodes;
        toCheckNodes.clear();
    }

    return resultList;
}

bool BreadthFirstSearch::Bipartite() {
    return false;
}


template<class T>
void BreadthFirstSearch::addVectors(vector<T> &base, vector<T> adder)
{
    for(int i=0; i<adder.size(); i++)
        base.push_back(adder[i]);
}
