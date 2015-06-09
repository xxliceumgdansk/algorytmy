#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next;
};

class BreadthFirstSearch
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        BreadthFirstSearch(vector<node*> nodes, int numberOfNodes);
        vector<int> SearchGraph();
        bool Bipartite();

    protected:
    private:
};

