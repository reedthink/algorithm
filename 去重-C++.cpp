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
    // cout << it - v.begin() << endl;
    // cout << *it << endl;
    v.resize(it - v.begin());
    // // v.erase(it, v.end());
    cout << "去重完毕:" << endl;
    pr(v);

    return 0;
}