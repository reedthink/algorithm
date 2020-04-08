#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createBT(queue<int> &q) //创建二叉树，将线性表中的数据放入二叉树中
{
    //必须传引用，否则队列的元素会被重复使用
    TreeNode *node = NULL;
    if (q.empty())
    {
        return NULL; //结束递归
    }
    int data = q.front();
    q.pop();
    node = (TreeNode *)malloc(sizeof(TreeNode));
    if (data != 0)
    {
        node->val = data;
        node->left = createBT(q);
        node->right = createBT(q);
    }
    else {
        node->val = 0;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
void preOrderTraveral(TreeNode *node) //前序遍历
{
    if (node == NULL)
        return;
    cout << node->val << endl;
    preOrderTraveral(node->left);
    preOrderTraveral(node->right);
}
void inOrderTraveral(TreeNode *node)
{
    if (node == NULL)
        return;
    inOrderTraveral(node->left);
    cout << node->val << endl;
    inOrderTraveral(node->right);
}
void postOrderTraveral(TreeNode *node)
{
    if (node == NULL)
        return;
    postOrderTraveral(node->left);
    postOrderTraveral(node->right);
    cout << node->val << endl;
}
int main()
{
    queue<int> q;
    int a[] = {3, 2, 9, 0, 0, 10, 0, 0, 8, 0, 4};
    for (int i = 0; i < 11; i++)
        q.push(a[i]);
    TreeNode *parent = createBT(q);
    cout << "前序遍历：" << endl;
    preOrderTraveral(parent);
    cout << "中序遍历：" << endl;
    inOrderTraveral(parent);
    cout << "后序遍历：" << endl;
    postOrderTraveral(parent);
    return 0;
}