//小顶堆
//其实本质上和大顶堆那个一样，只是写法不同
#include <iostream>
#include <vector>
using namespace std;
/**
 * 上浮调整
 * @param array  待调整的堆
 */
void upAdjust(vector<int> &array)
{
    //因为这个代码中我们将根节点下标定为0,那么左右子节点的下标分别为2*0+1,2*0+2
    //那么父节点下标就是孩子节点下标先-1再处以2

    int childIndex = array.size()-1;
    int parentIndex = (childIndex - 1) / 2;
    int temp = array[childIndex];
    while (childIndex > 0 && temp < array[parentIndex])
    {
        array[childIndex] = array[parentIndex];
        childIndex = parentIndex;
        parentIndex = (parentIndex - 1) / 2; //上溯
    }
    array[childIndex] = temp;
}
/**
 * 下沉调整
 * @param array  待调整的堆
 * @param parentIndex  要下沉的父节点
 * @param length 堆的有效大小
 */
void downAdjust(vector<int> &array, int parentIndex, int length)
{
    //temp保存父节点，用于最后赋值
    int temp = array[parentIndex];
    //因为这个代码中我们将根节点下标定为0,那么左右子节点的下标分别为2*0+1,2*0+2
    //那么父节点下标就是孩子节点下标先-1再处以2
    int childIndex = parentIndex * 2 + 1; //默认左孩子，因为是完全二叉树
    while (childIndex < length)
    {
        //默认是左孩子
        //如果有右孩子，且右孩子小于左孩子的值，则定位到右孩子
        if (childIndex + 1 < length && array[childIndex + 1] < array[childIndex])
        {
            childIndex++;
        }
        //如果父节点小于任何一个孩子的值，就直接跳出
        if (temp <= array[childIndex])
        {
            break;
        }
        array[parentIndex] = array[childIndex];
        parentIndex = childIndex;
        childIndex = childIndex * 2 + 1; //下沉
    }
    array[parentIndex] = temp;
}
/**
 * 构建堆
 * @param array 待调整的堆
 * 
 */
void buildHeap(vector<int> &array)
{
    // 从最后一个非叶子节点开始，依次做“下沉”调整
    for (int i = (array.size() - 2) / 2; i >= 0; i--)
    {
        downAdjust(array, i, array.size());
    }
}
int main()
{
    vector<int> v= {1, 3, 2, 6, 5, 7, 8, 9, 10, 0};
    // int a[] ; //10个
    // for (int i = 0; i < 10; i++)
    // {
    //     v.push_back(a[i]);
    // }
    upAdjust(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
    vector<int> array = {7, 1, 3, 10, 5, 2, 8, 9, 6};
    buildHeap(array);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}