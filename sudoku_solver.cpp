#include<iostream>
using namespace std;

class Sudoku
{
    int board[9][9];
    public:
    Sudoku(int board[9][9])
    {
        for(int i = 0;i<9;i++)
            for(int j = 0;j<9;j++)
                this->board[i][j] = board[i][j];
    }
    void displayBoard()
    {
        cout<<"SUDOKU BOARD: ";
        for(int i = 0;i<9;i++)
        {
            if(i%3 == 0) cout<<endl;
            for(int j = 0;j<9;j++)
            {
                if(j%3==0) cout<<" ";
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool isSafe(int num, int row, int col)
    {
        for(int i = 0;i<9;i++)
            if(board[row][i]==num)
                return false;
        
        for(int j = 0;j<9;j++)
            if(board[j][col]==num)
                return false;

        for(int i = (int(row/3)*3);i<((int(row/3)*3)+3);i++)
            for(int j = (int(col/3)*3);j<((int(col/3)*3)+3);j++)
                if(board[i][j]==num)
                    return false;
        
        return true;
    }
    void solve()
    {
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == 0)
                {
                    for(int val = 1;val<=9;val++)
                    {
                        if(isSafe(val, i, j))
                        {
                            board[i][j] = val;
                            solve();
                            board[i][j] = 0;
                        }
                    }
                    return;
                }
            }
        }
        displayBoard();
        return;
    }
};

int main()
{
    int board[9][9];
    // Empty space denoted by zero
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
            cin>>board[i][j];
    
    Sudoku s(board);
    s.solve();
    return 0;
}