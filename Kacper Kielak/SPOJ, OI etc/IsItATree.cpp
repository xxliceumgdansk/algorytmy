//SPOJ problem: http://www.spoj.com/problems/PT07Y/s

#include <cstdio>
#include <vector>

#define UNDEF -1

struct node
{
    int parent;
    std::vector<int> neighbours;
    int checkedNeighbours;
    bool visited;
};

node* generateGraph(int nodesNumber, int edgesNumber)
{
    node *nodes = new node[nodesNumber];
    for(int i=0; i<edgesNumber; i++)
    {
        int start, finish;
        scanf("%d", &start); scanf("%d", &finish);
        start--; finish--;
        nodes[start].neighbours.push_back(finish);
        nodes[finish].neighbours.push_back(start);
    }
    for(int i=0; i<nodesNumber; i++)
    {
        nodes[i].checkedNeighbours=0;
        nodes[i].parent=UNDEF;
        nodes[i].visited=false;
    }
    return nodes;
}

int getNextNodeNumber(int currentNodeNumber, node* nodes)
{
    while(nodes[currentNodeNumber].checkedNeighbours==nodes[currentNodeNumber].neighbours.size())
    {
        if(nodes[currentNodeNumber].parent==UNDEF)
            return UNDEF;

        currentNodeNumber=nodes[currentNodeNumber].parent;
    }

    int nextNodeNumber = nodes[currentNodeNumber].neighbours[nodes[currentNodeNumber].checkedNeighbours];
    nodes[currentNodeNumber].checkedNeighbours++;

    if(nextNodeNumber==nodes[currentNodeNumber].parent)
        nextNodeNumber=getNextNodeNumber(currentNodeNumber, nodes);
    else
        nodes[nextNodeNumber].parent=currentNodeNumber;

    return nextNodeNumber;
}

int main()
{
    int nodesNumber, edgesNumber;
    scanf("%d", &nodesNumber); scanf("%d", &edgesNumber);
    node *nodes = generateGraph(nodesNumber, edgesNumber);
    int currentNodeNumber=0;

    while(currentNodeNumber!=UNDEF)
    {
        if(nodes[currentNodeNumber].visited)
        {
            printf("NO");
            return 0;
        }
        nodes[currentNodeNumber].visited=true;
        currentNodeNumber=getNextNodeNumber(currentNodeNumber, nodes);
    }

    for(int i=0; i<nodesNumber; i++)
        if(nodes[i].neighbours.empty())
        {
            printf("NO");
            return 0;
        }

    printf("YES");
    return 0;
}
