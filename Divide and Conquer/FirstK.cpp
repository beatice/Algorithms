#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

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

//找到前k大元素，将其都放到右边
void arrangeRight(int a[], int s, int e, int k)
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
    int num = e - i + 1;    //计算比key大的数的数量
    if (num == k)       //如果比key大的数刚好有k个，直接返回
        return;
    else if (num > k)   //如果比key大的数多于k个，在key的右边元素中寻找前k大元素
        arrangeRight(a, i+1, e, k);
    else    //如果比key小的数少于k个，在key的左边元素中寻找前(k-num)大元素
        arrangeRight(a, s, i-1, k-num);
}

int main()
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    arrangeRight(a, 0, n-1, k);
    QuickSort(a, n-k, n-1);     //对右边的前k大元素进行快速排序
    for (int i = n-1; i >= n-k; i--)
        cout << a[i] << endl;
    return 0;
}
