#include <iostream>
#include <stack>
using namespace std;
//单调栈首先满足栈的定义：后进先出，然后再考虑保证单调

//本实例实现单调递增栈
stack<int> sta;

int main()
{
    sta.push(50);
    sta.push(30);
    sta.push(10);
    sta.push(3);
    //初始元素为3,10,30,50。3先出栈，此时sta为单调栈

    //添加元素
    insertNum(20);
    return 0;
}
void insertNum(int x)
{
    while (!sta.empty() && sta.top() < x)
    {
        sta.pop();
    }
    sta.push(x);
}