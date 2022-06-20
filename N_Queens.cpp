#include<iostream>
using namespace std;

class NQueens
{
    int n;
    int **board;
    public:
    NQueens(int n)
    {
        this->n = n;
        board = new int*[n];
        for(int i = 0;i<n;i++)
            board[i] = new int [n];
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                board[i][j] = 0;
    }
    void printBoard()
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    bool isSafe(int row, int col)
    {
        // Checking the row
        for(int i = col-1;i>=0;i--)
            if(board[row][i])
                return false;
        
        //Upper Diagonal
        for(int i = row, j = col; i>=0 && j>=0; i--, j--)
            if(board[i][j])
                return false;
        
        // Lower Diagonal
        for(int i = row, j = col; j>=0 && i<n;i++,j--)
            if(board[i][j])
                return false;
        
        return true;
    }
    bool NQueensSolver(int col)
    {
        if(n == col) return true;
        for(int i = 0;i<n;i++)
        {
            if(isSafe(i, col))
            {
                board[i][col] = true;
                if(NQueensSolver(col + 1))
                    return true;
                board[i][col] = false;
            }
        }
        return false;
    }
    void solve()
    {
        if(NQueensSolver(0))
            printBoard();
        else
            cout<<"NO SOLUTION EXISTS"<<endl;
    }
};

int main()
{
    int n;
    cin>>n;
    NQueens q(n);
    q.solve();
    return 0;
}