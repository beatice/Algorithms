
#include <iostream>
#include <cmath>

using namespace std;

/* 逆波兰表达式 */
double exp();

int main()
{
    cout << exp() << endl;      //输出逆波兰表达式的值
    return 0;
}

double exp()
{
    char s[20];     //用于存储逆波兰表达式中的各项
    cin >> s;   //读入逆波兰表达式中的一个项
    switch(s[0]){
        case '+': return exp() + exp();
        case '-': return exp() - exp();
        case '*': return exp() * exp();
        case '/': return exp() / exp();
        default: return atof(s);
        /*
         * 头文件： #include <stdlib.h>
         * 定义函数： double atof(const char *nptr);
         * 函数说明： atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分，如123.456或123e-2。
         * 返回值： 返回转换后的浮点型数。*/
        break;
    }
}
