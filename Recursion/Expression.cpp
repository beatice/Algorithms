
#include <iostream>
#include <cstring>

using namespace std;

/* 表达式求值 */
int factor_value();
int term_value();
int expression_value();

int main()
{
    cout << expression_value() << endl;     //输出表达式计算的值
    return 0;
}

int expression_value()      //计算一个表达式的值
{
    int result = term_value();      //求第一项的值
    while (true){
        char op = cin.peek();   //查看输入中一个字符，不取走
        if (op == '+' || op == '-'){  
            cin.get();      //从输入中取走一个字符
            if (op == '+')
                result += term_value();
            else
                result -= term_value();
        }
        else
            break;
    }
    return result;
}

int term_value()    //计算一个项的值
{
    int result = factor_value();
    while (true){
        char op = cin.peek();
        if (op == '*' || op == '/'){
            cin.get();
            if (op == '*')
                result *= factor_value();
            else
                result /= factor_value();
        }
        else
            break;
    }
    return result;
}

int factor_value()      //计算一个因子的值
{
    int result = 0;
    char c = cin.peek();
    if (c == '('){
        cin.get();
        result = expression_value();
        cin.get();
    }
    else{
        while(isdigit(c)){
            result = result * 10 + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}

/*
 * cin.peek()的返回值是一个char型的字符，其返回值是指针指向的当前字符，但它只是观测指针停留在当前位置并不后移；如果要访问的字符是文件结束符，则函数值是EOF（-1） 
 *
 * cin.get()用来从指定的输入流中提取一个字符（包括空白字符），函数的返回值就是读入的字符。若遇到输入流中的文件结束符，则函数值返回文件结束标志EOF(End Of File)，一般以-1代表EOF
 */
