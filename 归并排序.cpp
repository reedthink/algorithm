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

void Merge_sort_double(int *a, int n);
void Merge_sort_divide(int *a, int l, int r);

void Merge_sort(int a[], int n, int type) // 从小到大
{
    // type 为1 采用倍增法
    // type 为2 采用分治法
    if (type == 1)
    {
        Merge_sort_double(a, n);
    }
    else if (type == 2)
    {
        Merge_sort_divide(a, 0, n);
    }
}

// 倍增法
void Merge_sort_double(int *a, int len)
{
    
}

// 分治法
void Merge_sort_divide(int *a, int l, int r)
{
    if (r - l <= 1)
        return;
    int mid = l + ((r - l) / 2);
    Merge_sort_divide(a, l, mid);
    Merge_sort_divide(a, mid, r);
    int tmp[r] = {};
    merge(a + l, a + mid, a + mid, a + r, tmp + l);
    for (int i = l; i < r; i++)
        a[i] = tmp[i];
}

// 将两个有序的数组 a[i] 和 b[j] 合并为一个有序数组 c[k]。
void merge(int *a, int a_len, int *b, int b_len, int *c)
{
    // 想明白合并什么，怎么合并

    // 1 10 20
    // 0 3 15
    int i = 0, j = 0, k = 0;
    while (i < a_len && j < b_len)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    for (; i < a_len; i++, k++)
    {
        c[k] = a[i];
    }
    for (; j < b_len; j++, k++)
    {
        c[k] = b[j];
    }
}

int main()
{
    JustRead();
    Merge_sort(a, n, 2);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
/*

*/