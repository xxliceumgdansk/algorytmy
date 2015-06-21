#include "DFS.h"

#define -1 UNDEFINED;

DepthFirstSearch::DepthFirstSearch(vector<node*> _graph, int _numberOfNodes)
{
    graph = _graph;
    numberOfNodes = _numberOfNodes;
}

vector<int> DepthFirstSearch::SearchGraph() {
    vector<int> resultList;
    node* actualNode = graph[0];
    (*actualNode).parent = nullptr;
    while(actualNode!=nullptr)
    {
        resultList.push_back((*actualNode).number);
        actualNode = getNextNode(actualNode);
    }

    return resultList;
}

bool DepthFirstSearch::Bipartite() {
    return false;
}

node* getNextNode(node* actualNode)
{
    for(int i=0; (*actualNode).next[i]!=nullptr; i++)
    {
        node checkingNode = (*actualNode).next[i];
        if(!(*actualNode).next[i].wasVisited)
        {
            (*actualNode).next[i].parent = actualNode;
            (*actualNode).next[i].wasVisited=true;
            return (&((*actualNode).next[i]));
        }
    }

    return (*actualNode).parent;
}

template<class T>
void DepthFirstSearch::addVectors(vector<T> &base, vector<T> adder)
{
    for(int i=0; i<adder.size(); i++)
        base.push_back(adder[i]);
}
