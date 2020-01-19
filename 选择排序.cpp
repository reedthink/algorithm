#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
//寒假第一天，开始编写C++的排序算法
int Selection_sort(int a[], int n) //从小到大
{
    int min_index = 0; //保存该次循环的最小值下标

    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
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
    Selection_sort(a, n); //存在与全局变量同名的局部变量时，局部变量作用域内自然是局部变量
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
//完成
//git@github.com:reedthink/WinterVacation.git
//git push --set-upstream origin master