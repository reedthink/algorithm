#include <bits/stdc++.h>

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
