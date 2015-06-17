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
        template<class T> void addVectors(vector<T> &base, vector<T> adder);
        bool Bipartite();

    protected:
    private:
};

