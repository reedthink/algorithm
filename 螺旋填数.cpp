/**
 * 可用于方阵（行等于列的矩阵）
 * 
 * 
 */
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int num[n][n] = {};

    int k = 1;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            num[i][j] = k;
            k++;
        }
        for (int j = i; j < n - 1 - i; j++)
        {
            num[j][n - 1 - i] = k;
            k++;
        }
        for (int j = n - 1 - i; j > i; j--)
        {
            num[n - 1 - i][j] = k;
            k++;
        }
        for (int j = n - 1 - i; j > i; j--)
        {
            num[j][i] = k;
            k++;
        }
    }
    if (k < n * n)
        num[n / 2][n / 2] = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}