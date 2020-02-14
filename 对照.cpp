#include <bits/stdc++.h>
//本文件仅为测出IO的时间，便于对比各排序的真实排序时间
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;

int a[maxn];
int n;
void JustRead()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int main()
{
    JustRead();
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
