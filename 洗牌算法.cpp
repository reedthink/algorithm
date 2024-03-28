// 常用的随机算法
#include <iostream>
#include <vector>

using namespace std;

void shuffle(vector<int> &nums)
{
    srand((unsigned)time(NULL)); // 需要重设随机数种子
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        // 最后一个元素不需要交换了
        int randIdx = rand() % i;
        // cout << "randIdx" << randIdx << endl;
        swap(nums[i], nums[randIdx]);
    }
}
/*关于正确性：
假设5张牌，刚开始第五个位置可能被洗成任意一张牌，每个牌选中的概率都是1/5。（换言之，对于第一张牌，等价于从牌堆中抽取任意一张牌）
到了第四个位置，表面上看只可能从前四张牌任意选一张，概率是1/4，但是需要注意，这四张牌都没有在第一轮选中，所以需要乘以4/5，真实概率为1/4 * 4/5,也就是1/5
对于之后的牌，同理
*/

inline int a = 0;
int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    shuffle(v);
    for (auto it : v)
        cout << it << " ";
    return 0;
}