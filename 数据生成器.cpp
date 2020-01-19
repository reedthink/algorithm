#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e4 + 7;
int main()
{
    int n;
    srand(time(NULL));
    printf("%d\n",maxn);
    for (int i = 0; i < maxn; i++)
    {
        printf("%d ", rand());
    }
    return 0;
}
/*
g++ 数据生成器.cpp -o build/数据生成器 && ./build/数据生成器 >small.in
g++ 数据生成器.cpp -o build/数据生成器 && ./build/数据生成器 >sort.in
*/