#include <bits/stdc++.h>

// alt+f3恢复边框

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
void BubbeSort(int a[], int n) //从小到大
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
    }
}
//写来写去还是冒泡写着顺手哦

int main()
{
    JustRead();
    BubbeSort(a, n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
/*

*/