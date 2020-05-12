/**
 * AVL树终于来了！
 * 平衡二叉树是一种排序树，其中每一个节点的左子树和右子树的高度差至多是1
 * AVL树是一种平衡二叉树的实现
*/
#include <stdio.h>
#include <iostream>
using namespace std;
struct BitNode //结点结构
{
    int data;                 //结点数据
    int bf;                   //结点平衡因子
    BitNode *lchild, *rchild; //左右孩子指针
};

//右单旋 RR
void R_Rotate(BitNode *p)
{
    
}
int main()
{
    cout << sizeof(int) << endl;
    return 0;
}