#include <iostream>
#include <vector>

using namespace std;

//计算x有多少个二进制位
int countBits(int x)
{
    int ans = 0;
    while(x)
    {
        x/=2;
        ans++;
    }
    return ans;
}

//打印二进制
void printBit(int x)
{
    vector<int> ans;
    while(x)
    {
        ans.push_back(x%2);
        x/=2;
    }
    for(auto it = ans.rbegin(); it!=ans.rend() ; it++)
    {
        cout << *it;
    }
    cout << endl;
}

bool isPalindrome(int x)
{
    vector<int> ans;
    while(x)
    {
        ans.push_back(x%2);
        x/=2;
    }
    auto it1=ans.begin();
    auto it2=ans.rbegin();
        
    for(; it1!=ans.end();it1++,it2++)
    {
        if(*it1!=*it2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for(int i=1 ;i<33;i++)
    {
        int n = i;
        cout << "n = " << n << ":";
        cout << countBits(n) << endl;
        cout << isPalindrome(n) << endl;
        printBit(n);
    }  
    return 0;
}