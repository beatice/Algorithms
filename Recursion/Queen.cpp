
#include <iostream>
#include <cmath>

using namespace std;

/* N皇后问题 */

int N;
int queenPos[100];      //用于存放算好的皇后的位置，最左上角的位置是(0,0)

void NQueen(int k);

int main()
{
    cin >> N;
    NQueen(0);      //从第0行开始摆放皇后
    return 0;
}

void NQueen(int k)      //在0～k-1行的皇后都已经摆放好的情况下，摆放第k行及其后的皇后
{
    int i;
    if (k == N){    //N个皇后已经摆放好，则输出结果
        for (i = 0; i < N; ++i)
            cout << queenPos[i] + 1 << " ";     //因为存放皇后位置的矩阵默认从0开始计数，需要加1，表示正确的列
        cout << endl;
        return;
    }

    for (i = 0; i < N; ++i){    //遍历第k行皇后可以摆放的位置
        int j;
        for (j = 0; j < k; ++j){    //和已经摆放好的k个皇后的位置进行比较，看是否存在冲突
            if (queenPos[j] == i ||
                abs(queenPos[j]-i) == abs(k-j))
                //当第k行皇后的列号与已摆放皇后的列好相同时，或第k行皇后所在位置在已摆放皇后的对角线上，产生冲突
                break;
        }
        if (j == k){    //第k行皇后当前所在位置，与已摆放k个皇后的位置都不存在冲突
            queenPos[k] = i;
            NQueen(k+1);
        }
    }
}
