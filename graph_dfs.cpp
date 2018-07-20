#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFSUtil(int s, bool *v);
    void DFS(void);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFSUtil(int s, bool v[])
{
    v[s] = true;
    cout<<s<<" ";
    vector<int>::iterator i;
    for(i = adj[s].begin(); i!=adj[s].end(); i++)
    {
        if(!v[*i])
            DFSUtil(*i,v);
    }
}

void Graph::DFS(void)
{
    bool *visited = new bool[V];
    for(int v=0; v<V; v++)
        visited[v] = false;
    for(int i=0;i<V; i++)
    {
        if(!visited[i])
            DFSUtil(i,visited);
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.DFS();
}
