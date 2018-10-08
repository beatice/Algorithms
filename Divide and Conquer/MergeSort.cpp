#include <iostream>

using namespace std;

int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
int b[10];      //实现归并排序的过程中，需要使用一个多余数组进行数据缓存

//将已实现归并排序的左右两部分排序输出
void Merge(int a[], int s, int e, int m, int tmp[])
{
    int pLeft = s, pRight = m+1;    //pLeft,pRight分别是已实现归并排序的左右两部分的首元素的数组下标
    int Pos = 0;    //缓存数组的数组下标
    while (pLeft <= m && pRight <= e){
        if (a[pLeft] < a[pRight])   //如果左部分元素小于右部分元素
            tmp[Pos++] = a[pLeft++];    //将左部分元素放入缓存数组
        else                        //如果左部分元素大于右部分元素
            tmp[Pos++] = a[pRight++];   //将右部分元素放入缓存数组
    }
    while (pLeft <= m)      //如果左部分元素还没有放完
        tmp[Pos++] = a[pLeft++];
    while (pRight <= e)     //如果右部分元素还没有放完
        tmp[Pos++] = a[pRight++];
    for(int i = 0; i < e - s + 1; i++)
        a[s+i] = tmp[i];
}

//归并排序，复杂度O(nlogn)
void MergeSort(int a[], int s, int e, int tmp[])
{
    if (s < e){     //当s <= e时，需要排序的元素只有一个
        int mid = s + (e - s)/2;        //找到要排序的所有元素的中间位置
        MergeSort(a, s, mid, tmp);      //对左部分元素进行归并排序
        MergeSort(a, mid+1, e, tmp);    //对右部分元素进行归并排序
        Merge(a, s, e, mid, tmp);
    }
}

int main()
{
    int size = sizeof(a)/sizeof(int);
    MergeSort(a, 0, size-1, b);
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
