#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int BinarySearch(int lb, int ub, vector<int> a, int k) //二分查找到第一个等于k的位置
{
    //目前还不够健壮，没有处理数组中不含查询元素的情况
    lb -= 1; //暂时不明白为啥要这样
    while (ub > lb + 1)
    {
        int mid = (lb + ub) / 2;
        if (a[mid] >= k)
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }
    return ub; //下标
}
void pr(vector<int> a)
{
    for (auto it : a)
    {
        cout << it << ',';
    }
    cout << '\n';
}
int main()
{
    vector<int> v = {2, 1, 3, 5, 4, 5, 5, 5};
    sort(v.begin(), v.end());

    pr(v);

    int k = 5;
    cout << BinarySearch(0, v.size(), v, k);

    // auto i = lower_bound(v.begin(), v.end(), 1) - v.begin();

    // cout << i << endl;

    return 0;
};