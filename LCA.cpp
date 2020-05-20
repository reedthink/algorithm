#include <stdio.h>
#include <vector>
using namespace std;
//二分搜索求LCA
const int MAX_V = 1000;
vector<int> G[MAX_V];
int root;

int parent[MAX_V];
int depth[MAX_V];

void dfs(int v,int p,int d)
{
    parent[v]=p;
    depth[v]=d;
    int sz=G[v].size();
    for(int i=0 ;i<sz;i++)
    {
        if(G[v][i]!=p)
            dfs(G[v][i],v,d+1);
    }
}
void init() 
{
    dfs(root,-1,0);
}
int lca(int u,int v)
{
    while(depth[u]>depth[v]) u=parent[u];
    while(depth[v]>depth[u]) v=parent[v];
    while(u!=v)
    {
        u=parent[u];
        v=parent[v];

    }
    return u;
}


int main()
{
    return 0;
}