#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000;
// 查询策略类似lower_bound，二分查找到第一个等于k的位置, 如果没有，返回-1
// 与lower_bound()不同，lower_bound 查找的是数组中第一个大于等于val的数。
int LowerBinarySearch(int left, int right, vector<int> a, int k)
{
    int ret = -1;
    int mid;
    right -= 1;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (a[mid] < k)
        {
            // 往右边找
            left = mid + 1; // 因为mid对应的元素已经探测过，不等于。直接往右边找
            ret = left;
        }
        else
        {
            // 往左边找(区间往左侧缩小)
            right = mid; // 因为mid对应的元素已经探测过，可能等于，所以不更改
            ret = right;
        }
    }
    // 打个补丁
    if (a[ret] != k)
    {
        ret = -1;
    }
    return ret; //下标
}
//查询策略类似upper_bound，二分查找到最后一个等于k的位置
int UpperBinarySearch(int left, int right, vector<int> a, int k)
{
    // 实现思路：一直往右侧收缩区间
    int ret = -1; //数组中不含查询元素的情况，返回-1
    int mid;
    right-=1;
    while (left < right)
    {
        time--;
        mid = (left + right) / 2;
        // cout << left << ' ' << right << ' ' << mid<<endl;
        if (a[mid] > k)
        {
            // 往左边找(区间往左侧缩小)
            right = mid; // 因为mid对应的元素已经探测过，不可能等于，但是这个写法是找最后一个大于等于k的值
            ret = right;
        }
        else
        {
            // 往右边找
            left = mid+1; // 因为mid对应的元素已经探测过，可能等于，所以留在mid位置
            ret = left;
        }
    }
    // cout << left << ' ' << right << ' ' << mid<<endl;
    // 打个补丁
    if (a[ret] != k)
    {
        ret = -1;
    }
    return ret; //下标
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
    vector<int> v = {2, 1, 3, 5, 4, 5, 5};
    sort(v.begin(), v.end());

    pr(v);

    int k = 5;
    cout << "下标：" << LowerBinarySearch(0, v.size(), v, k) << endl; // 左闭右开
    cout << "下标：" << UpperBinarySearch(0, v.size(), v, k) << endl;

    // auto i = lower_bound(v.begin(), v.end(), 1) - v.begin();

    // cout << i << endl;

    return 0;
};