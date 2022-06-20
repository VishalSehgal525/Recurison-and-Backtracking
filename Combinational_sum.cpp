#include<iostream>
#include<stack>
using namespace std;

void displayReverse(stack<int> s)
{
    stack<int> s1;
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

void printSubsequence(int *arr, int n, int itr, stack<int> s, int sum, int newsum)
{
    if(newsum>sum) return;
    if(arr[itr]>sum) return;
    if(itr>=n)
    {
        if(newsum == sum)
            displayReverse(s);
        return;
    }
    s.push(arr[itr]);
    printSubsequence(arr, n, itr, s, sum, newsum+arr[itr]);
    s.pop();
    printSubsequence(arr, n, itr+1, s, sum, newsum);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    stack<int> s;
    cout<<"Enter the sum: ";
    int sum;
    cin>>sum;
    printSubsequence(arr, n, 0, s, sum, 0);
    return 0;
}