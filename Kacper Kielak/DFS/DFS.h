#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *parent;
		struct node *next;
		bool wasVisited;
};

class DepthFirstSearch
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        DepthFirstSearch(vector<node*> nodes, int numberOfNodes);
        vector<int> SearchGraph();
        node* getNextNode(node* actualNode);
        bool Bipartite();
        template<class T> void addVectors(vector<T> &base, vector<T> adder);

    protected:
    private:
};

