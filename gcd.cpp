#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//放弃可读性，进行优化
//但是在10的9次方范围内，差距极小。
int nb_gcd(int a, int b)
{
    if (a == b)
        return a;
    if ((a & 1) == 0 && (b & 1) == 0)
        return gcd(a >> 1, b >> 1) << 1;
    else if ((a & 1) == 0 && (b & 1) != 0)
    {
        return gcd(a >> 1, b);
    }
    else if ((a & 1) != 0 && (b & 1) == 0)
        return gcd(a, b >> 1);
    else
    {
        int big = a > b ? a : b;
        int small = a < b ? a : b;
        return gcd(big - small, small);
    }
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {

        int a, b;
        a = rand();
        b = rand();
        if (gcd(a, b) != nb_gcd(a, b))
        {
            printf("写错了。%d %d\n", a, b);
        }
        printf("%d %d %d\n", a, b, gcd(a, b));
    }

    return 0;
}