//SPOJ problem: http://www.spoj.com/problems/PT07Y/s

#include <cstdio>
#include <vector>

#define UNDEF -1

struct Node
{
    int parent;
    std::vector<int> neighbours;
    int checkedNeighbours;
    bool visited;

};

Node* generateGraph(int nodesNumber, int edgesNumber)
{
    Node *graph = new Node[nodesNumber];
    for(int i=0; i<nodesNumber; i++)
    {
        graph[i].parent=UNDEF,
        graph[i].checkedNeighbours=0,
        graph[i].visited=false;
    }

    for(int i=0; i<edgesNumber; i++)
    {
        int start, finish;
        scanf("%d", &start); scanf("%d", &finish);
        start--; finish--;
        graph[start].neighbours.push_back(finish);
        graph[finish].neighbours.push_back(start);
    }

    return graph;
}

class TreeChecker
{
    public:
        TreeChecker(Node* _graph, int _nodesNumber):
            graph(_graph),
            nodesNumber(_nodesNumber)
        {}

        bool isATree()
        {
            if(!isTreeStructured())
                return false;

            if(!wasEveryNodeVisited())
                return false;

            return true;
        }

    private:
        Node* graph;
        int nodesNumber;

        bool isTreeStructured()
        {
            int currentNode=0;

            while(currentNode!=UNDEF)
            {
                if(graph[currentNode].visited)
                    return false;

                graph[currentNode].visited=true;
                currentNode=getNextNode(currentNode);
            }

            return true;
        }

        bool wasEveryNodeVisited()
        {
            for(int i=0; i<nodesNumber; i++)
                if(!graph[i].visited)
                    return false;

            return true;
        }

        int getNextNode(int currentNode)
        {
            while(wasEveryNeighbourChecked(currentNode))
            {
                if(graph[currentNode].parent==UNDEF)
                    return UNDEF;

                currentNode=graph[currentNode].parent;
            }

            int nextNode = graph[currentNode].neighbours[graph[currentNode].checkedNeighbours];
            //number of checked neighbours is also an index of next unchecked neighbour ^^
            graph[currentNode].checkedNeighbours++;

            if(nextNode==graph[currentNode].parent)
                nextNode=getNextNode(currentNode);
            else
                graph[nextNode].parent=currentNode;

            return nextNode;
        }

        bool wasEveryNeighbourChecked(int currentNode)
        {
            if(graph[currentNode].checkedNeighbours!=graph[currentNode].neighbours.size())
                return false;

            return true;
        }
};

int main()
{
    int nodesNumber, edgesNumber;
    scanf("%d", &nodesNumber); scanf("%d", &edgesNumber);
    if(nodesNumber!=edgesNumber+1)
    {
        printf("NO");
        return 0;
    }

    Node *graph = generateGraph(nodesNumber, edgesNumber);

    TreeChecker treeChecker(graph, nodesNumber);
    if(treeChecker.isATree())
        printf("YES");
    else
        printf("NO");

    return 0;
}
