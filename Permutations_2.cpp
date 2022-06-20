#include<iostream>
using namespace std;

void display(int *arr, int n)
{
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void permutations(int *arr, int n, int index)
{
    if(index == n)
    {
        display(arr, n);
        return;
    }
    for(int i = index;i<n;i++)
    {
        swap(arr[index], arr[i]);
        permutations(arr, n, index+1);
        swap(arr[index], arr[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"PERMUTATIONS GENERATED: "<<endl;
    permutations(arr, n, 0);
    
    return 0;
}