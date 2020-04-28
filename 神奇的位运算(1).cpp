// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int xor_sum = 0;
        for (auto it : nums)
            xor_sum ^= it;
        int d = 1;
        //把d变为0000001000000，1的位置与xor_sum的最低的那个1位置一样
        while ((d & xor_sum) == 0)
        {
            d = d * 2;
        }
        //之后通过这个d中的1来把数字分为两组（其实核心是把a，b分开）。
        //因为a不等于b，那么xor_sum一定不为0,所以a和b的异或和（也就是上边的xor_sum）的某一位上为1,代表a和b在对应的二进制位相异
        //我们借助d和nums[i]相与，将数组切分为两组
        vector<int> r(2);
        for (auto it : nums)
        {
            if (d & it)
            {
                r[0] ^= it;
            }
            else
            {
                r[1] ^= it;
            }
        }
        return r;
    }
};