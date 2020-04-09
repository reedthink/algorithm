#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef int temp;

void show(temp a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
/**
 * 切分，双边循环法
 * @param a 待交换的数组
 * @param lo 起始下标
 * @param hi 结束下标
*/
int partition0(temp a[], int lo, int hi)
{
    int i = lo, j = hi + 1; //左右扫描指针
    //为了避免最差情况，可以随机一个合法下标，然后与首位置交换
    temp v = a[lo];         //切分元素，取第一个位置作基准元素

    while (i < j)
    {
        //控制左指针比较，并右移
        while (a[++i] < v)
        {
            if (i == hi)
            {
                break;
            }
        }

        //控制右指针比较，并左移
        while (a[--j] > v)
        {
            if (j == lo)
            {
                break;
            }
        }
        if (i >= j)// 不多余，因为下边还有一条交换语句
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
    //得到基准元素位置
    int j = partition0(a, lo, hi);
    //根据基准元素，进行递归排序
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
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort0(a, 0, n - 1);
    printf("%d\n", n);
    show(a, n);
    return 0;
}