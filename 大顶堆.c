#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#define false 0
#define true 1
#define bool int //奇怪，c11明明支持bool了啊，害

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
const int MaxData = INT_MAX;
struct HeapStruct
{
    ElementType *Elements;
    int Size;
    int Capacity;
};
//创建容量为MaxSize的空最大堆
MaxHeap Create(int MaxSize)
{
    MaxHeap H = malloc(sizeof(MaxHeap));
    H->Elements = malloc(
        (MaxSize + 1) * sizeof(ElementType)); //-> ： 调用结构体指针指向的结构体的成员
    (*H).Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData; //提前定义一个最大值,作为“哨兵”
    return H;
}
bool IsFull(MaxHeap H)
{
    return H->Capacity == H->Size;
}
bool IsEmpty(MaxHeap H)
{
    return H->Size == 0;
}
bool Insert(MaxHeap H, ElementType x)
{
    if (IsFull(H))
    {
        printf("最大堆已满");
        return false;
    }
    int i = ++(H->Size); //i指向插入后堆中最后一个元素的位置。注意，这里其实可以不加括号.
    for (; H->Elements[i / 2] < x; i /= 2)
    {
        H->Elements[i] = H->Elements[i / 2]; //上滤x
    }
    H->Elements[i] = x;
    return true;
}
//从最大堆中取出最大元素，并删除一个结点
ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H))
    {
        printf("最大堆已空");
        return 0;
    }
    MaxItem = H->Elements[1]; //取出根节点，即最大值

    //用最大堆最后一个元素从根节点开始过滤下层节点
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;                    //如果还有右子节点，让Child指向左右子节点的较大者
        if (temp >= H->Elements[Child]) //如果尾结点值temp大于等于当前Parent节点的子节点的较大值，说明这个parent位置是temp的目标位置
            break;
        else
            H->Elements[Parent] = H->Elements[Child]; //如果不是，将较大子节点赋给当前parent,然后继续下滤
    }
    H->Elements[Parent] = temp;
    return MaxItem;
    //这种堆的实现方法与线段树一致，都是用数组模拟存放。完全二叉树用数组模拟的时候，中间是不会出现空缺的
}
//下滤，将H中以H->Elements[p]为根的子堆调整为最大堆
void PercDown(MaxHeap H, int p)
{
    int Parent, Child;
    ElementType X = H->Elements[p]; //取出根节点存放的值
    for (Parent = p; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++; //如果还有右子节点，让Child指向左右子节点的较大者
        if (X >= H->Elements[Child])
            break;
        else //下滤
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}
//调整H->Elements[]中的元素，使满足最大堆的有序性。假设所有元素已经存在H->Elements[]中
void BuildHeap(MaxHeap H)
{
    int i;
    //从最后一个结点的父结点开始，到根节点1
    for (i = H->Size / 2; i > 0; i--)
    {
        PercDown(H, i);
    }
}
int main()
{
    // printf("%d\n",INT_MAX);
    int a[10] = {81, 91, 59, 16, 96, 55, 50, 34, 97, 39};
    MaxHeap H = Create(10);
    for (int i = 1; i < 11; i++)
    {
        H->Elements[i] = a[i - 1];
        H->Size++;
    }
    BuildHeap(H);

    // for (int i = 0; i < 10; i++)
    // {
    //     Insert(H, a[i]);
    // }
    for (int i = 1; i <= H->Size; i++)
    {
        printf("%d,", H->Elements[i]);
    }
    printf("\n");
    printf("%d\n", DeleteMax(H));
    for (int i = 1; i <= H->Size; i++)
    {
        printf("%d,", H->Elements[i]);
    }
    return 0;
}