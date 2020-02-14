#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
int a[maxn];
int n;
void JustRead()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}
int Shell_sort(int a[], int n) //从小到大
{
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                swap(a[j], a[j - h]);
            }
        }
        h = h / 3;
    }
} //改进版的插入排序，利用插入排序的特点，将局部进行有序化，之后对整体进行插入排序

int main()
{
    JustRead();
    Shell_sort(a, n); //存在与全局变量同名的局部变量时，局部变量作用域内自然是局部变量
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
/*

*/