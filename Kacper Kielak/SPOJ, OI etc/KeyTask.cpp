//http://www.spoj.com/problems/CERC07K/

#include<cstdio>
#include<vector>
#include<list>

#define UNDEF -1
#define WALL '#'
#define ACTUALPOS '*'
#define FREE '.'
#define EXIT 'X'

struct Vector2D
{
    int x, y;
    Vector2D(int _x, int _y):
        x(_x),
        y(_y)
        {}
};

struct Node
{
    char place;
    Vector2D parentPos;
    bool visited;
    int distance;
    Node(char _place):
        place(_place),
        visited(false),
        distance(UNDEF),
        parentPos(UNDEF, UNDEF)
        {}
};

struct Map
{
    Vector2D size;
    Node **board;

    Map(Node **_board, Vector2D _size):
        board(_board),
        size(_size)
        {}
};

class BFS
{
    public:
        BFS(Map _map, Vector2D _startPos):
            map(_map),
            startPos(_startPos)
        {
            map.board[startPos.y][startPos.x].visited=true;
            map.board[startPos.y][startPos.x].distance=0;
            countShortestPath();
        }

        int getShortestPath()
        {
            return shortestPath;
        }

        int getDistanceOf(Vector2D pos)
        {
            return map.board[pos.y][pos.x].distance;
        }

    private:
        Map map;
        Vector2D startPos;
        int shortestPath;
        std::list<Vector2D> checkQueue;

        void countShortestPath()
        {
            shortestPath=UNDEF;
            checkQueue.push_back(startPos);
            while(!checkQueue.empty())
            {
                checkFrontNeighbours();
            }
        }

        void checkFrontNeighbours()
        {
            Vector2D checkingPos(checkQueue.front());

            checkingPos.x--;
            if(isProfitable(checkingPos))
                addToQueue(checkingPos);

            checkingPos.x+=2;
            if(isProfitable(checkingPos))
                addToQueue(checkingPos);

            checkingPos.x--; checkingPos.y--;
            if(isProfitable(checkingPos))
                addToQueue(checkingPos);

            checkingPos.y+=2;
            if(isProfitable(checkingPos))
                addToQueue(checkingPos);
        }

        void addToQueue(Vector2D position)
        {
            Vector2D parentPos(checkQueue.front());
            checkQueue.push_back(position);
            map.board[position.y][position.x].visited=true;
            map.board[position.y][position.x].parentPos = parentPos;
            map.board[position.y][position.x].distance = map.board[parentPos.y][parentPos.x].distance+1;
        }

        bool isProfitable(Vector2D position)
        {
            if(position.x < map.size.x &&
               position.y < map.size.y &&
               position.x > 0 &&
               position.y > 0 &&
               !map.board[position.y][position.x].visited &&
               map.board[position.y][position.x].place!=WALL)
                return true;
        }
};

int main()
{
    int height, width;
    scanf("%d", &height); scanf("%d", &width);

    Vector2D mapSize(width, height);
    Node board[mapSize.y][mapSize.x];
    Vector2D startPos;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            char place;
            scanf("%c", &place);
            board[i][j](place);
            if(place==ACTUALPOS)
                startPos(j, i);
        }

    Map map(board, mapSize);
    BFS(map, startPos);

    int shortestPath = BFS.getShortestPath();
    if(shortestPath!=UNDEF)
        printf("Escape possible in %d steps.", shortestPath);
    else
        printf("The poor student is trapped!");

    return 0;
}
