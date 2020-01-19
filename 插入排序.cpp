#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
int Insertion_sort(int a[], int n) //从小到大
{
    
}
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
    Insertion_sort(a, n); //存在与全局变量同名的局部变量时，局部变量作用域内自然是局部变量
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
