#include<iostream>
#include<stack>
using namespace std;

class PalindromePartitioning
{
    string s;
    stack<string> stk;
    public:

    PalindromePartitioning(string s)
    {
        this->s = s;
    }

    void reverseDisplay(stack<string> s)
    {
        stack<string> s1;
        while(!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty())
        {
            cout<<s1.top()<<" ";
            s1.pop();
        }
        cout<<endl;
    }

    bool isSafe(int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void Partitioning(int index)
    {
        if(index == s.length())
        {
            reverseDisplay(stk);
            return;
        }
        for(int i = index; i<s.length(); i++)
        {
            if(isSafe(index, i))
            {
                stk.push(s.substr(index, i-index+1));
                Partitioning(index + stk.top().length());
                stk.pop();
            }
        }
    }
};

int main()
{
    string s;
    cin>>s;
    PalindromePartitioning p(s);
    p.Partitioning(0);
    return 0;
}