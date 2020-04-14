/**
 * 求二叉树的高度
 * 树的高度等于左子树与右子树的最大值+1
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
struct BinTree
{
    int value;
    BinTree *Left, *Right;
    BinTree()
    {
        value = 0;
        Left = NULL;
        Right = NULL;
    }
};
BinTree *createBT(queue<int> &q)
{
    BinTree *node = NULL;
    if (q.empty())
    {
        return NULL;
    }
    int data = q.front();
    q.pop();
    node = new BinTree(); //构造函数拯救代码量和发量！
    if (data != 0)
    {
        node->value = data;
        node->Left = createBT(q);
        node->Right = createBT(q);
    }

    return node;
}
void InOrderTraversal(BinTree *BT)
{
    auto T = BT;
    stack<BinTree *> S;
    while (T || !S.empty())
    {
        while (T)
        {
            S.push(T);
            T = T->Left;
        }
        if (!S.empty())
        {
            T = S.top();
            S.pop();
            // printf("%5d,", T->value);
            cout << T->value << ',';
            T = T->Right;
        }
    }
}
int GetHeight(BinTree *node)
{
    int HL, HR, ret;
    if (node)
    {
        //依然是递归求解
        HL = GetHeight(node->Left);
        HR = GetHeight(node->Right);
        ret = max(HL, HR);
        return ret + 1;
    }
    return 0;
}
int main()
{
    queue<int> q;
    vector<int> a = {3, 2, 9, 0, 0, 10, 0, 0, 8, 0, 4};
    // vector<int> a = {3,2};

    for (int i = 0; i < a.size(); i++)
        q.push(a[i]);
    BinTree *be = createBT(q);

    cout << "树的高度：" << endl;
    cout << GetHeight(be) << endl;
    return 0;
}
