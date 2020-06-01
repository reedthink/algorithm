#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int Weight;
    struct TreeNode *Left, *Right;
    bool operator<(const TreeNode &t) const
    {
        return Weight > t.Weight;
    }
    TreeNode(int w)
    {
        Left = nullptr;
        Right = nullptr;
        Weight = w;
    }
};

priority_queue<TreeNode> que;

void Huffman(TreeNode *T);

void levelTraversal_newline(TreeNode *node);

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        auto it = new TreeNode(i);
        que.push(*it);
    }
    // while (!que.empty())
    // {
    //     cout << que.top().Weight << "gg";
    //     que.pop();
    // }
    auto it = new TreeNode(0);
    Huffman(it);
    levelTraversal_newline(it);
    return 0;
}
void Huffman(TreeNode *T)
{
    //二叉堆写的太复杂了，这里我用了优先队列
    while (que.size() > 1)
    {
        //因为优先队列里存的不是指针，而是结构体，但是这里的哈夫曼树是用链表构造的，必须用一个结构体指针中转一下
        TreeNode it(0);
        auto ptr = new TreeNode(0);
        *ptr = que.top(); //把优先队列里的结构体内容复制到指针ptr指向的内存
        it.Left = ptr;    //构建哈夫曼左子树
        que.pop();

        ptr = new TreeNode(0);
        *ptr = que.top();
        it.Right = ptr;
        que.pop();

        it.Weight = it.Left->Weight + it.Right->Weight;
        que.push(it);
    }
    *T = que.top();
}
//分层遍历哈夫曼树。层次遍历,分层换行
void levelTraversal_newline(TreeNode *node)
{
    auto T = node;
    if (T)
    {
        queue<TreeNode *> q;
        q.push(T);
        while (!q.empty())
        {
            int cur = q.size();
            while (cur > 0) // 一直访问到当前层的最后一个节点
            {
                cur--;
                auto now = q.front();
                cout << now->Weight << ',';
                q.pop();

                if (now->Left)
                {
                    q.push(now->Left);
                }
                if (now->Right)
                    q.push(now->Right);
            }
            printf("\n");
        }
    }
}