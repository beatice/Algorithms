#include <iostream>

using namespace std;

int LowerBound(int a[], int size, int p);

int main()
{
    int a[] = {1, 3, 4, 6, 7, 10, 12, 15, 16, 20, 27, 32, 34, 35, 36, 38, 42, 46, 48, 52};
    int size = 20;
    int p;
    cin >> p;
    int result = LowerBound(a, size, p);
    cout << result << endl;
    return 1;
}

//LowerBound函数：在包含size个元素、从小到大排序的int数组a中查找比给定元素p小的、下标最大的元素，如果找到，则返回元素下标，如果找不到，则返回-1
int LowerBound(int a[], int size, int p)
{
    int L = 0;		//查找区间的左端点
    int R = size - 1;	//查找区间的右端点
    int LastPos = -1;	//到目前为止找到的最优解
    while (L <= R){		//如果查找区间不为空则继续查找
        int mid = L + (R - L)/2;	//取查找区间中间元素的下标
        if (a[mid] >= p)
            R = mid - 1;	//设置新的查找区间右端点
        else{
            LastPos = mid;
            L = mid + 1;	//设置新的查找区间左端点
        }

    }
    return LastPos;
}//时间复杂度O(log(n))
