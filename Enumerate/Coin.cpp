#include <iostream>
#include <cstring>

using namespace std;

char Left[3][7];        //天平左边硬币
char Right[3][7];       //天平右边硬币
char Result[3][7];      //结果
bool IsFake(char c, bool light);    //light为真表示假设假币为轻，否则表示假设假币为重

/* POJ1013 称硬币 */
int main()
{
    int t;      //
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; ++i)     //
            cin >> Left[i] >> Right[i] >> Result[i];
        for (char c = 'A'; c <= 'Z'; ++c){      //
            if (IsFake(c, true)){
                cout << c << " is the counterfeit coin and it it light." << endl;
                break;
            }
            else if (IsFake(c, false)){
                cout << c << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }
    return 0;
}

bool IsFake(char c, bool light)
{
    for (int i = 0; i < 3; ++i){
        char *pLeft, *pRight;
        if(light){
            pLeft = Left[i];
            pRight = Right[i];
        }
        else{
            pLeft = Right[i];
            pRight = Left[i];
        }
        switch (Result[i][0]){
            case 'u':
                if (strchr(pRight, c) == NULL)
                    return false;
                break;
            case 'd':
                if (strchr(pLeft, c) == NULL)
                    return false;
                break;
            case 'e':
                if (strchr(pLeft, c) || strchr(pRight, c))
                    return false;
                break;
        }
    }
    return true;
}
