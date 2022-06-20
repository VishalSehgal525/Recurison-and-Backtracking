#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int n;
    vector<int> *v;
    int *colors;
    int m;
    public:

    Graph(int n)
    {
        this->n = n;
        v = new vector<int>[n];
        colors = new int[n];
        memset(colors, 0, n);
    }

    void add_edge(int f, int t)
    {
        v[f].push_back(t);
        v[t].push_back(f);
    }

    void display()
    {
        for(int i = 0;i<n;i++)
        {
            for(int x: v[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }

    void display_colors()
    {
        for(int i = 0;i<n;i++)
            cout<<colors[i]<<" ";
        cout<<endl;
    }

    void set_colors(int m)
    {
        this->m = m;
    }

    bool isSafe(int color, int f)
    {
        for(int x: v[f])
            if(colors[x] == color)
                return false;
        return true;
    }

    bool color_the_graph(int itr)
    {
        if(itr == n)
        {
            display_colors();
            return true;
        }
        for(int i = 1;i<=m;i++)
        {
            if(isSafe(i, itr))
            {
                colors[itr] = i;
                if(color_the_graph(itr+1))
                    return true;
                colors[itr] = 0;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    Graph g(n);
    bool b = 1;
    while(b)
    {
        cout<<"FROM: ";
        int f;
        cin>>f;
        cout<<"TO: ";
        int t;
        cin>>t;
        g.add_edge(f,t);
        cout<<"To continue adding edges press 1 or press 0 to exit: ";
        cin>>b;
    }
    cout<<"Enter the number of colors: ";
    cin>>n;
    g.set_colors(n);
    g.color_the_graph(0)?cout<<"YES": cout<<"NO";
    cout<<endl;
    return 0;
}