
#include <iostream>

using namespace std;

/* 汉洛塔问题 */
void Hanoi(int n, char src, char mid, char dest)
//将src座上的n个盘子，以mid座为中转，移动到dest座
//src座上最上方盘子编号时src_n
{
    if (n == 1){    //只需移动一个盘子
        cout << src << "->" << dest << endl;    //直接将盘子从src座移动到dest座即可
        return;
    }

    Hanoi(n-1, src, dest, mid);     //先将n-1个盘子从src移动到mid
    cout << src << "->" << dest << endl;    //再将最后一个盘子从src移动到dest
    Hanoi(n-1, mid, src, dest);     //最后将n-1个盘子从mid移动到dest
    return;
}

int main()
{
    char a, b, c;   //三个座
    int n;      //盘子数量
    cin >> n >> a >> b >> c;
    Hanoi(n, a, b, c);
    return 0;
}
