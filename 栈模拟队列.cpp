#include <stack>
#include <iostream>
using namespace std;
stack<int> st1, st2;
void st_push(int x);
void st_pop();
void tran();
int st_top();
int main()
{
    st_push(1);
    st_push(2);
    st_push(3);
    cout << st_top() << endl;
    st_pop();
    cout << st_top() << endl;
    st_pop();
    st_push(4);
    cout << st_top() << endl;
    st_pop();
    cout << st_top() << endl;
    st_pop();
    return 0;
}
void st_push(int x)
{
    st1.push(x);
}
void st_pop()
{
    if (st2.empty())
    {

        tran();
    }
    if (!st2.empty())
        st2.pop(); //避免段错误
}
void tran()
{
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }
}
int st_top()
{
    if (st2.empty())
    {
        tran();
    }
    return st2.top();
}