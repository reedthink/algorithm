/**
 * 二叉树的前中后序非递归遍历
 * 还有层次遍历
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
    BinTree() //构造函数拯救代码量！
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
    node = new BinTree(); //构造函数拯救代码量！
    if (data != 0)
    {
        node->value = data;
        node->Left = createBT(q);
        node->Right = createBT(q);
    }

    return node;
}

void PreOrderTraversal(BinTree *node);
void InOrderTraversal(BinTree *BT);
void PostOrderTraversal(BinTree *node);
void levelTraversal(BinTree *node);

int main()
{
    queue<int> q;
    vector<int> a = {3, 2, 9, 0, 0, 10, 0, 0, 8, 0, 4};
    for (int i = 0; i < 11; i++)
        q.push(a[i]);
    BinTree *be = createBT(q);
    cout << "前序遍历:" << endl;
    PreOrderTraversal(be);
    cout << endl;
    cout << "中序遍历:" << endl;
    InOrderTraversal(be);
    cout << endl;

    cout << "后序遍历:" << endl;
    // PostOrderTraversal(be);//后序的待写
    cout << endl;

    cout << "层次遍历:" << endl;

    levelTraversal(be);
    return 0;
}
//前序
void PreOrderTraversal(BinTree *node)
{
    auto T = node;
    stack<BinTree *> st;
    while (T || !st.empty())
    {
        while (T)
        {
            st.push(T);
            cout << T->value << ',';
            T = T->Left;
        }
        if (!st.empty())
        {
            T = st.top();
            st.pop();
            T = T->Right;
        }
    }
}
//中序
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
//这个有难度，待写
void PostOrderTraversal(BinTree *node)
{
    auto T = node;
    stack<BinTree *> st;
    while (T || !st.empty())
    {
        while (T)

        {
            st.push(T);
            T = T->Left;
        }
        if (!st.empty())
        {
            T = st.top();
            st.pop();
            T = T->Right;
        }
        // if (T)
        // {
        //     cout << T->value << ',';
        // }
    }
}
//层次遍历
void levelTraversal(BinTree *node)
{
    auto T = node;
    if (T)
    {
        queue<BinTree *> q;
        q.push(T);
        while (!q.empty())
        {
            auto now = q.front();
            cout << now->value << ',';
            q.pop();
            if (now->Left)
            {
                q.push(now->Left);
            }
            if (now->Right)
                q.push(now->Right);
        }
    }
}
