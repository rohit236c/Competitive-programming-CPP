#include <iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class graph
{
    int V;
    // list<int>*l;
    map<T,list<T> > h;
public:
    graph()
    {

    }
    void addedge(T u,T v,bool bider=true)
    {
        h[u].push_back(v);
        if(bider)
        {
            h[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:h)
        {
            cout<<i.first<<"->";
            for(auto vertex:i.second)
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        queue<T>q;
        map<T,int>dist;
        map<T,T>par;
        for(auto i:h)
        {
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        par[src]=src;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neigh:h[node])
            {
                if(dist[neigh]==INT_MAX)
                {
                    q.push(neigh);
                    dist[neigh]=dist[node]+1;
                    par[neigh]=node;
                }
            }
        }
        for(auto i:h)
        {
            T node = i.first;
            cout<<"dist to"<<" "<<node<<" "<<"from "<<src<<"is "<<dist[node];
            cout<<endl;
        }
    }
    void dfshelper(T node,map<T,bool> &visited,list<T>&order)
    {

        visited[node]=true;
        for(T neighbour:h[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour,visited,order);
            }
        }
        order.push_front(node);
    }
    void dfssort()
    {

        map<T,bool>visited;
        list<T>order;
        for(auto i:h)
        {
            T node = i.first;
            if(!visited[node])
            {
                dfshelper(node,visited,order);
            }
        }
        for( T city:order)
        {
            cout<<city<<"-->";
        }
    }

};

int main()
{

    graph<int>g;
    g.addedge(1,2,false);
    g.addedge(1,3,false);
    g.addedge(2,4,false);
    g.addedge(3,4,false);
    //g.print();
    g.dfssort();

    return 0;
}
