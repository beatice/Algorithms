#include <iostream>

using namespace std;
/* 完美立方 */
int main()
{
    int N;
    cin >> N;
    for (int a = 2; a <= N; ++a)
        for (int b = 2; b < a; ++b)
            for (int c = b; c < a; ++c)
                for (int d = c; d < a; ++d)
                    if (a*a*a == (b*b*b + c*c*c + d*d*d))
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
    return 0;
}
