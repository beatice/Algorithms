#include <iostream>

using namespace std;

int a[] = {93, 27, 30, 2, 8, 12, 2, 8, 30, 89};

//交换两个元素的值
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//快速排序，平均复杂度O(logN)，最坏复杂度O(N2)
void QuickSort(int a[], int s, int e)
{
    if (s >= e)     //如果只有一个元素需要排序，则返回
        return;
    int i = s, j = e;   //s表示排序元素的首元素下标，e表示排序元素的尾元素下标
    int key = a[s];     //key为选择的中间数
    while (i != j){
        while (i < j && a[j] >= key)    
            j--;
        swap(a[i], a[j]);
        while (i < j && a[i] <= key)
            i++;
        swap(a[i], a[j]);
    }
    QuickSort(a, s, i-1);
    QuickSort(a, i+1, e);
}

int main()
{
    int size = sizeof(a)/sizeof(int);
    QuickSort(a, 0, size-1);
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
