//树状数组求逆序数
class Solution
{
public:
    int a[55000], n;//树状数组a下标从1开始，原数组也是
    int lowbit(int x)
    {
        return x & (-x);
    }
    int sum(int i)
    {
        int sum = 0;
        while (i)
        {
            sum += a[i];
            i -= lowbit(i); //上溯
        }
        return sum;
    }
    void update(int i, int k)
    {
        while (i < n)
        {
            a[i] += k;
            i += lowbit(i); //向下更新
        }
    }
    int reversePairs(vector<int> &nums)
    {
        int ans = 0;
        auto t = nums;
        sort(t.begin(), t.end());
        int m = unique(t.begin(), t.end()) - t.begin();
        n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] = lower_bound(t.begin(), t.begin() + m, nums[i]) - t.begin() + 1; //离散化
        }
        for (int i = nums.size() - 1; i >= 0; i--)//访问原数组离散化后的每一个元素
        {
            ans += sum(nums[i]-1);//求树状数组对应的数组v的1到nums[i]-1的前缀和（v没有显示给出，只是中间需要的概念），因为是按照数组nums逆序添加的数字，所以这时候求v的前缀和就是数字nums[i]的逆序数
            update(nums[i], 1);
        }
        return ans;
    }
};