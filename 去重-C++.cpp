#include <bits/stdc++.h>
using namespace std;
void pr(vector<int> v)
{
    for (auto it : v)
    {
        cout << it << ',';
    }
    cout << '\n';
}

int main()
{
    vector<int> v = {1, 2, 33, 3, 73, 3, 12, 2, 73, 3, 3};

    //去重前必须排序
    cout << "升序数组:" << endl;
    sort(v.begin(), v.end()); //升序

    pr(v);

    auto it = unique(v.begin(), v.end());

    // cout << v.size() << endl;
    cout << "unique后的样子：" << endl;
    pr(v);
    v.resize(it - v.begin()); //重新分配内存空间
    // // v.erase(it, v.end());//擦除末端多余空间
    cout << "去重完毕:" << endl;
    pr(v);

    return 0;
}