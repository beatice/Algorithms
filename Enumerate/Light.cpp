
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

/* POJ1222 熄灯问题 */

int GetBit(char c, int i){     //用于读取灯矩阵中对应位置灯的状态，或用于读取对应位置开关状态
    //取c的第i位
    return (c >> i) & 1;
}

void SetBit(char &c, int i, int v){     //用于初始化灯矩阵
    //设置c的第i位为v
    if (v)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}

void Flip(char &c, int i){      //用于调整灯矩阵灯的状态，由点亮变为熄灭或由熄灭变为点亮
    //将c的第i位取反
    c ^= (1 << i);
}

void OutputResult(int t, char result[]){
    //输出结果
    cout << "PUZZLE # " << t << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << GetBit(result[i], j);
            if (j < 5)
                cout << " ";
        }
        cout << endl;
    }
}

int main(){
    char oriLights[5];      //最初灯矩阵，一个比特代表一盏灯，0表示灯的初始状态为熄灭，1表示灯的初始状态为点亮
    char lights[5];         //不停变化的灯矩阵
    char result[5];        //结果开关矩阵，一个比特代表一个按钮，1表示需要按下对应的按钮（按钮处及周围的灯的状态需要改变），0表示不需要按下对应的按钮
    char switchs;           //某一行的开关状态
    int T;
    cin >> T;               //输入案例数
    for (int t = 1; t <= T; ++t){
        memset(oriLights, 0, sizeof(oriLights));    //将初始灯状态统一设为0
        /*
         * void *memset(void *s, int ch, size_t n);
         * 函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
         * memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法。
         */
        for (int i = 0; i < 5; ++i){    //读入初始灯状态
            for (int j = 0; j < 6; ++j){
                int s;
                cin >> s;
                SetBit(oriLights[i], j, s);
            }
        }
        for (int n = 0; n < 64; n++){   //遍历首行开关的64种状态
            memcpy(lights, oriLights, sizeof(oriLights));
            /*
             * 函数原型：void *memcpy(void *dest, const void *src, size_t n);
             * 功能：从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
             * 返回值：函数返回指向dest的指针。
             * 所需头文件：C语言：#include<string.h>，C++：#include<cstring>
             */
            switchs = n;    //第i行的开关状态
            for (int i = 0; i < 5; ++i){    //逐行进行处理
                result[i] = switchs;    //将第i行的开关方案存入结果开关矩阵中
                for (int j = 0; j < 6; ++j){
                    if (GetBit(switchs, j)){    //如果第j列的开关为1，需要修改按钮处及周围灯的状态
                        if (j > 0)      //当处理的不是首列的灯时
                            Flip(lights[i], j - 1);     //改左灯的状态
                        Flip(lights[i],j);      //改当前开关位置的灯的状态
                        if (j < 5)      //当处理的不是末列的灯时
                            Flip(lights[i], j + 1);     //改右灯的状态
                    }
                }
                if (i < 4)      //当处理的不是末行的灯时
                    lights[i+1] ^= switchs;     //修改下一行的灯的状态（下一行灯的状态会受到当前行开关处理的影响）
                switchs = lights[i];       //第i+1行开关方案和第i行的灯的情况相同
            }
            if (lights[4] == 0){    //如果最后一行的灯全灭
                OutputResult(t, result);    //输出结果
                break;
            }
        }   // for (int n = 0; n < 64; n++)
    }
    return 0;
}

/*
输入案例：
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
*/
