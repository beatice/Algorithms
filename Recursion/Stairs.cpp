
#include <iostream>

using namespace std;

/* 爬楼梯 */
int stairs(int n);

int main()
{
    int n;
    while (cin >> n){
        cout << stairs(n) << endl;
    }
    return 0;
}

int stairs(int n)   //计算n级楼梯的走法
{
    //边界条件n==1, n==2
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return stairs(n-1) + stairs(n-2);
    //n级楼梯的走法=先走1级后，n-1级台阶的走法+先走2级后，n-2级台阶的走法
}
