#include <vector>
#include <queue>

using namespace std;

struct node {
	public:
		int number;
		struct node *next;
		bool isChecked;
};

class BreadthFirstSearch
{
    int numberOfNodes;
    vector<node*> graph;

    public:
        BreadthFirstSearch(vector<node*> nodes, int numberOfNodes);
        vector<int> SearchGraph();
        bool Bipartite();
        vector<int> getNeighboursAndCheck(vector<int> checkingNodes);
        template<class T> void addVectors(vector<T> &base, vector<T> adder);

    protected:
    private:
};

