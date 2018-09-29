
#include <iostream>

using namespace std;

/* 分苹果 */
int apple(int M, int N);    //M为苹果数，N为盘子数

int main()
{
    int t, M, N;
    cin >> t;   //读入案例数
    while (t--){
        cin >> M >> N;
        cout << apple(M,N) << endl;
    }
    return 0;
}

int apple(int M, int N)
{
    if (M < N)      //当盘子数多于苹果数时，必然有N-M个盘子为空
        return apple(M,M);
    if (M == 0)     //当苹果数为0时，有一种摆放方法，即所有盘子均为空
        return 1;
    if (N == 0)     //当盘子数为0时，没有盘子可以用于摆放，摆放方法为0
        return 0;
    return apple(M, N-1) + apple(M-N,N);
    //将M个苹果放在N个盘子的放法总数(M>=N) = 有盘子为空时的放法总数 + 没有盘子没空时的放法总数
}
