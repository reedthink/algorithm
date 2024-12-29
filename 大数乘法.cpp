#include<iostream>

using namespace std;

void mul(int a[], int b[], int ans[], int len_a, int len_b) {
    int Len = len_a + len_b;

    for (int i = 0; i < Len; i++)
        ans[i] = 0;
    for (int i = 0; i < Len - 1; i++) {
        for (int j = 0; j <= i; j++)
            ans[i] += a[j] * b[i - j];
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
}
int main()
{
    return 0;
}