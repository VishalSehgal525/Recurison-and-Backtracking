#include<iostream>
#include<stack>
using namespace std;

class Maze
{
    int n;
    int **maze;
    stack<char> s;
    bool **visited;
    public:

    Maze(int n, int **maze)
    {
        this->n = n;
        this->maze = maze;
        visited = new bool*[n];
        for(int i = 0;i<n;i++)
            visited[i] = new bool[n];
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                visited[i][j] = 0;
    }

    void displayReverse(stack<char> stk)
    {
        stack<char> s1;
        while(!stk.empty())
        {
            s1.push(stk.top());
            stk.pop();
        }
        while(!s1.empty())
        {
            cout<<s1.top()<<" ";
            s1.pop();
        }
        cout<<endl;
    }
    
    bool isSafe(int row, int col)
    {
        if(row<0 || col<0) return false;
        if(row>=n || col>=n) return false;
        if(maze[row][col]==0) return false;
        return true;
    }

    void goal(int row, int col)
    {
        if(row == n-1 && col == n-1)
        {
            displayReverse(s);
            return;
        }
        if(isSafe(row+1, col) && !visited[row+1][col])
        {
            s.push('D');
            visited[row+1][col] = 1;
            goal(row+1, col);
            s.pop();
            visited[row+1][col] = 0;
        }
        if(isSafe(row, col-1) && !visited[row][col-1])
        {
            s.push('L');
            visited[row][col-1] = 1;
            goal(row, col-1);
            visited[row][col-1] = 0;
            s.pop();
        }
        if(isSafe(row, col+1) && !visited[row][col+1])
        {
            s.push('R');
            visited[row][col+1] = 1;
            goal(row, col+1);
            s.pop();
            visited[row][col+1] = 0;
        }
        if(isSafe(row-1, col) && !visited[row-1][col])
        {
            s.push('U');
            visited[row-1][col] = 1;
            goal(row-1, col);
            visited[row-1][col] = 0;
            s.pop();
        }
    }
};

int main()
{
    int n;
    cin>>n;
    int **maze;
    maze = new int*[n];
    for(int i = 0;i<n;i++)
        maze[i] = new int[n];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>maze[i][j];
    Maze m(n, maze);
    m.goal(0,0);
    return 0;
}