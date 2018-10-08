#include <iostream>
#include <cmath>
using namespace std;

double EPS = 1e-6;

//计算函数的值
double f(double x)
{
    return x*x*x - 5*x*x + 10*x - 80;   
}

//求函数的根
double Equation(){
    double x1 = 0;    //求根的区间左端点
    double x2 = 100;  //求根的区间右端点
    double root, y;   //root为根，y为函数值
    int triedTimes = 0;   //记录尝试次数
    while (x1 <= x2){
        triedTimes++;
        root = x1 + (x2 - x1)/2;
        y = f(root);
        if (fabs(y) < EPS){
            cout << triedTimes << endl;
            return root;
        }
        else if (y > 0)
            x2 = root;
        else
            x1 = root;

    }
}

int main()
{
    double result = Equation();
    cout << result << endl;
    return 1;
}

