/**
 * 根据树的前序和中序遍历来重建二叉树,后序和中序同理
 * 前序遍历：1  2  4  5  7  8  3  6 

 * 中序遍历：4  2  7  5  8  1  3  6

 * 后序遍历：4  7  8  5  2  6  3  1

 * 层次遍历：1  2  3  4  5  6  7  8
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        int preStart = 0, preLast = pre.size() - 1;
        int inStart = 0, inLast = vin.size() - 1;
        return BuildSubTree(pre, preStart, preLast, vin, inStart, inLast);
    }
    TreeNode *BuildSubTree(vector<int> pre, int preStart, int preLast, vector<int> vin, int inStart, int inLast)
    {
        if (inLast < inStart || preLast < preStart)
            return NULL;
        auto root = new TreeNode(pre[preStart]);
        int i = inStart;
        while (vin[i] != pre[preStart])
        {
            i++;
        }
        int dis = i - inStart; //左子树的元素数量，此函数的核心
        root->left = BuildSubTree(pre, preStart + 1, preStart + dis, vin, inStart, i - 1);
        root->right = BuildSubTree(pre, preStart + dis + 1, preLast, vin, i + 1, inLast);
        return root;
    }

    void postOrderTr(TreeNode *root)
    {
        if (root)
        {
            postOrderTr(root->left);
            postOrderTr(root->right);
            cout << root->val << ',';
        }
    }
};

int main()
{
    vector<int> pre = {1, 2, 4, 5, 7, 8, 3, 6};
    vector<int> vin = {4, 2, 7, 5, 8, 1, 3, 6};
    Solution a;
    auto root = a.reConstructBinaryTree(pre, vin);
    a.postOrderTr(root);
    return 0;
}
