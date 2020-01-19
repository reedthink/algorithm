#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int a[maxn];
int check(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int z = check(n);
    if (z == 0)
    {
        puts("Accepted!");
    }
    else
    {
        printf("第%d个元素有问题\n", z);
    }
    return 0;
}
