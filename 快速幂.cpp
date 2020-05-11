#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n >= 0)
    {
        return quick_pow(x, n);
    }
    else
    {
        return 1.0 / quick_pow(x, -1ll * n);
    }
}
double quick_pow(double x, long long n)
{
    double ret = 1;
    while (n > 0)
    {
        if (n % 2)
            ret = ret * x;
        x = x * x;
        n /= 2;
    }
    return ret;
}

int main()
{
    int n;
    double x;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
    return 0;
}