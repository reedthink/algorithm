//单点更新，区间查询
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 51000;
int a[N], n0;
int lowbit(int x)
{
    return x & (-x);
}
int sum(int i)
{
    int sum = 0;
    while (i != 0) {
        sum += a[i];
        i -= lowbit(i);
    }
    return sum;
}
void add(int i, int k)
{
    while (i <= n0) {
        a[i] += k;
        i += lowbit(i);
    }
}
int main()
{
    int n, t, c1, c2;
    cin >> t;
    for (int no = 1; no <= t; no++) {
        cin >> n;
        n0 = n;
        printf("Case %d:\n", no);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> c1;
            add(i, c1);
        }
        string command;
        while (cin >> command, command != "End") {
            cin >> c1 >> c2;
            if (command == "Query")
                printf("%d\n", sum(c2) - sum(c1 - 1));
            else if (command == "Add")
                add(c1, c2);
            else
                add(c1, -c2);
        }
    }
    return 0;
}
//test.in
/*
2
6
1 3 2 9 4 6
Query 1 6
Add 1 1
Query 1 6
Sub 1 1
Query 1 6
Query 5 5
End
6
1 3 2 9 4 6
Query 1 6
Add 1 1
Query 1 6
Query 5 6
End
*/