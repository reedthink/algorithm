//并查集
#include <stdio.h>
using namespace std;
const int maxn = 100000;
int fa[maxn];
void makeSet(int size)
{
    for (int i = 0; i < size; i++)
        fa[i] = i;
}
int find(int x) //啦啦啦，递归
{
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unionSet(int x, int y)
{
    // x 与 y 所在家族合并
    x = find(x);
    y = find(y);
    if (x == y) //原本就在一个家族里就不管了
        return;
    fa[x] = y; //把 x 的祖先变成 y 的祖先的儿子
}

int main()
{

    return 0;
}