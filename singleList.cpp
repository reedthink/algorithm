//单链表，包含链表的插入和删除
#include <iostream>
#include <time.h>
using namespace std;
struct myList
{
    int num;      //数据域
    myList *next; //指针域
};
//增加，传入两个参数，一个是上个节点，一个是新增节点的数据。单项链表只支持在尾部添加元素
myList *addNode(myList last, int a)
{
    myList *zan = (myList *)malloc(sizeof(myList));
    (*zan).num = a;
    (*zan).next = nullptr;
    return zan;
}
//输出，注意：C和C++的函数参数实际上是传值，因此，假如该值（形参）为数组名或者指针，则修改他们指向的东西就是修改原数据。woc，对于结构体不是
void outList(myList begin)
{
    printf("%d ", (begin).num);
    if ((begin).next == nullptr)
        return;
    outList(*begin.next);
}
void deleteList(myList *now)
{
    //对于单向链表，只能删除当前元素的下一个元素
    if ((*now).next == nullptr)
        return;
    myList *zan = (*(*now).next).next;
    free((*now).next);
    (*now).next = zan;
}
void freeAll(myList *a)
{

    if ((*a).next != nullptr)
        freeAll((*a).next);

    if ((*a).next != nullptr)
    {
        free((*a).next); //我好像明白啥叫程序设计了
        (*a).next = nullptr;
    }
}
int main()
{
    int n = 10;
    int a[10];
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10;
    // cout<<"输入的数据：           ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';

    //初始化
    myList be; //起点总是特殊，不是吗
    be.num = a[0];
    be.next = nullptr;
    myList *now = &(be); //指向链表首地址

    for (int i = 1; i < n; i++)
    {
        (*now).next = addNode(*now, a[i]); //先把新节点的地址传给上个元素的指针域
        now = (*now).next;                 //让now指向新节点
    }
    // cout<<"链表数据：            ";
    outList(be);
    cout << "\n";
    // cout<<be.next<<endl;

    deleteList(&be);
    outList(be); // cout<<"删除第二个节点后的链表:";
    // cout<<be.next<<endl;

    cout << "\n";
    freeAll(&be); //释放所有节点内存
    cout << be.next << endl;

    return 0;
}