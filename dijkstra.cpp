#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_V = 30010;
int preNode[MAX_V];

struct CNode{
    int k;  //有向边的终点
    int w;  //权值
};

struct cmp
{
    bool operator () (CNode a, CNode b)
    {
        return a.w > b.w;
    }
};

vector< vector<CNode> > S;    //整个图的邻接表


//小顶堆，用于保存未确定为最短路径的顶点
priority_queue<CNode, vector<CNode>, cmp> q;


void dijkstra(int n)
{
    int d[MAX_V]; //源点到i的距离
    memset(d, 0x3f, sizeof(d));
    CNode p;
    p.k = 0;
    p.w = 0;
    q.push(p);
    d[0] = 0;
    while(!q.empty())
    {
        p = q.top();    //取出最短的未确定顶点
        q.pop();
        if (d[p.k] < p.w)
            continue;
        for (int i = 0 ; i < S[p.k].size() ; i ++) // 以p.k为中间点，更新其他顶点的路径
        {
            //j为以p.k为起点的边的个数
            CNode t;
            t= S[p.k][i]; // 要更新路径长度的终点
            if (d[t.k] > d[p.k] + t.w) // 如果当前顶点可以以p.k为中间点更新路径
            {
                d[t.k] = d[p.k] + t.w;
                t.w = d[t.k];
                q.push(t);
                preNode[t.k] = p.k; //记录前驱顶点
            }
        }
    }
    for (int i = 0 ; i < n ; i ++)
        cout << "源点到顶点 " << i << " 的最短路径为" << d[i] << endl;
}
void print_path(int v)
{
    if (v == 0)
    {
        cout << v;
        return;
    }
    print_path(preNode[v]);
    cout << " -> " << v;
}
int main()
{
    //输入
    int n, m, a, b, c;
    cin >> n >> m;
    S.clear();
    S.resize(n+1);
    CNode p1, p2;
    for (int i = 1 ; i <= m ; i ++)
    {
        cin >> a >> b >> c;
        p1.k = b;
        p1.w = c;
        p2 = p1;
        p2.k = a;
        S[a].push_back(p1);
        S[b].push_back(p2);
    }

    dijkstra(n);
    for (int i = 1 ; i < n ; i ++)
    {
        print_path(i);
        cout << endl;
    }
    return 0;
}
/*
7 10
0 1 2
0 2 5
1 2 4
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
*/