#include <iostream>
#define INF 0x3f3f3f3f3f

using namespace std;

const int N = 2100;

struct node//存边
{
    int x,y,len;//表示x到y的距离是len
} a[N*2];

long long dis[N];//dis[i]表示从源点到i点的距离是dis[i]
int t,n;

void bellman()
{
    for(int i = 1; i <= n; i++)//初始化
        dis[i] = INF;
    dis[1] = 0;

    for(int i = 1; i < n; i++)//核心代码，n个点
        for(int j = 1; j <= t; j++)//t条边
        {
            dis[a[j].y] = min(dis[a[j].x]+a[j].len, dis[a[j].y]);
            dis[a[j].x] = min(dis[a[j].y]+a[j].len, dis[a[j].x]);//无向图双向考虑
        }
}

int main()
{
    while(cin>>t>>n)
    {
        for(int i = 1; i <= t; i++)//输入
            cin>>a[i].x>>a[i].y>>a[i].len;

        bellman();

        cout<<dis[n]<<endl;
    }

    return 0;
}