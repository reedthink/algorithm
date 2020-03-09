//双链表
#include <iostream>
#include <time.h>
using namespace std;
struct Node {
    int value; //数据域
    Node* left; //指针域
    Node* right; //指针域
};
Node* insertNode(int i, Node& p)
{
    Node* zan;
    zan = (Node*)malloc(sizeof(Node));

    (*zan).value = i;

    p.right = zan;
    (*zan).left = &p;
    (*zan).right = nullptr;
    return zan;
}
void delNode(Node* p) //删除当前节点
{
    //如果有上个节点
    if (p->left != nullptr) {
        p->left->right = p->right; //修改上个节点的指向
    }
    p->right->left = p->left;
    free(p);
}
void printList(Node& be) //从左向右
{
    // printf("%p %d %p %p\n", be.left, be.value, &be, be.right);
    printf("%d ", be.value);
    if (be.right == nullptr)
        return;
    printList(*be.right);
}

int main()
{

    Node be; //首位
    be.left = nullptr;
    be.right = nullptr;

    Node* ptr; //中转指针
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i + 1;
        printf("%d ", a[i]);
    }
    puts("");
    be.value = a[0];
    ptr = &be;
    for (int i = 1; i < 10; i++) {

        ptr = insertNode(a[i], *ptr);
    }
    printList(be);
    ptr = be.right->right->right; //删除第四个元素
    delNode(ptr);
    puts("");
    printList(be);

    return 0;
}
//