#include<iostream>
#include<stack>
using namespace std;

//By making use of a hashmap

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

bool checkHashmap(bool *hashmap, int n)
{
    for(int i = 0;i<n;i++)
        if(hashmap[i] == false)
            return false;
    return true;
}

void permutations(int *arr, int n, stack<int> s, bool *hashmap)
{
    if(checkHashmap(hashmap, n))
    {
        displayReverse(s);
        return;
    }
    for(int i = 0;i<n;i++)
    {
        if(hashmap[i] == false)
        {
            s.push(arr[i]);
            hashmap[i] = true;
            permutations(arr, n, s, hashmap);
            hashmap[i] = false;
            s.pop();
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    stack<int> s;
    bool hashmap[n];
    for(int i = 0;i<n;i++)
        hashmap[i] = false;
    cout<<"PERMUTATIONS GENERATED: "<<endl;
    permutations(arr, n, s, hashmap);
    
    return 0;
}