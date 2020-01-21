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
int Insertion_sort(int a[], int n) //从小到大
{
    int i, j, key;
    for (int i = 1; i < n; ++i)
    {
        key = a[i];
        j=i-1;
        while((j>=0)&&(a[j]>key))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
/*
基础的插入排序，插入方法就是数组模拟，然后插入时，对前部元素进行后移。
*/