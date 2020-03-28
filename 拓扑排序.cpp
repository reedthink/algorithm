//虽然也叫排序，但是属于图论算法中
/* 
设置一个队列（方便使用优先队列，从小到大输出）,
将所有入度为 0 的顶点入队。找入度为 0 的顶点,
只要依次出队即可。删除边的操作转化为将该点关联的所有点的入度减1 。
 */
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 10005;
int n, m, cnt;
bool a[MAXN][MAXN]; //邻接矩阵
int indeg[MAXN];
//indeg[i],第i点的入度，ans[]答案队列
vector<int> ans;
queue<int> q;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        indeg[y]++;
    }
}
void topo_sort()
{
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (a[u][i]) {
                indeg[i]--;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }
    }
}
void output()
{
    if (ans.size() < n) {
        cout << "有环！无法正常进行拓扑排序" << endl;
        return;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}
int main()
{
    input();
    topo_sort();
    output();
    return 0;
}
/*
10 6
1 2
2 3 
4 5 
5 6
8 9
9 10
*/
