/**
 * 根据树的前序和中序遍历来重建二叉树,后序和中序同理
 * 
 * 前序遍历：1  2  4  5  7  8  3  6 

 * 中序遍历：4  2  7  5  8  1  3  6

 * 后序遍历：4  7  8  5  2  6  3  1
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
    TreeNode *reConstructBinaryTree(vector<int> post, vector<int> vin)
    {
        int postStart = 0, postLast = post.size() - 1;
        int inStart = 0, inLast = vin.size() - 1;

        return BuildSubTree(post, postStart, postLast, vin, inStart, inLast);
    }
    TreeNode *BuildSubTree(vector<int> post, int postStart, int postLast, vector<int> vin, int inStart, int inLast)
    {
        if (inLast < inStart || postLast < postStart)
            return NULL;

        auto root = new TreeNode(post[postLast]);
        int i = inStart;
        while (vin[i] != post[postLast])
        {
            i++;
        }
        int dis = i - inStart; //左子树的元素数量,函数核心！
        root->left = BuildSubTree(post, postStart, postStart + dis - 1, vin, inStart, i - 1);
        root->right = BuildSubTree(post, postStart + dis, postLast - 1, vin, i + 1, inLast);
        return root;
    }

    void preOrderTr(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << ',';
            preOrderTr(root->left);
            preOrderTr(root->right);
        }
    }
};

int main()
{
    vector<int> post = {4, 7, 8, 5, 2, 6, 3, 1};
    vector<int> vin = {4, 2, 7, 5, 8, 1, 3, 6};
    Solution a;
    auto root = a.reConstructBinaryTree(post, vin);
    a.preOrderTr(root);
    return 0;
}

// TreeNode *helper(const vector<int> &in, int il, int ir, const vector<int> &post, int pl, int pr)
// {
//     if (il >= ir || pl >= pr)
//         return nullptr;
//     const int mid = post[pr - 1];
//     const int dis = find(in.begin() + il, in.begin() + ir, mid) - (in.begin() + il);
//     // 左子树有 dis 个节点
//     TreeNode *const root = new TreeNode(mid);
//     root->left = helper(in, il, il + dis, post, pl, pl + dis);
//     root->right = helper(in, il + dis + 1, ir, post, pl + dis, pr - 1);
//     return root;
// }

// TreeNode *buildTree(vector<int> &in, vector<int> &post)
// {

//     return helper(in, 0, in.size(), post, 0, post.size());
// }
