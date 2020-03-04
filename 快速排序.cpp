#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef int temp;
//exch 我们直接采用swap
void show(temp a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
//切分
int partition0(temp a[], int lo, int hi)
{
    int i = lo, j = hi + 1; //左右扫描指针
    temp v = a[lo]; //切分元素
    while (true) {
        while (a[++i] < v)
            if (i == hi)
                break;
        while (v < a[--j])
            if (j == lo)
                break;
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]);
    return j;
}
//lo is low ,hi is high
void sort0(temp a[], int lo, int hi)
{
    if (hi <= lo)
        return;
    int j = partition0(a, lo, hi);
    sort0(a, lo, j - 1);
    sort0(a, j + 1, hi);
}

int a[120000];
int main()
{

    // srand(time(NULL));
    // int n = 10;
    // for (int i = 0; i < n; i++)
    //     a[i] = rand() % 107;
    // // show(a, n);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort0(a, 0, n - 1);
    printf("%d\n", n);
    show(a, n);
    return 0;
}