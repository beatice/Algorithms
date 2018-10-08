#include <iostream>
#include <algorithm>

using namespace std;

int x[100005];

int distance(int N, int C);

int main()
{
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> x[i];
    sort(x, x + N);
    int dis = distance(N, C);
    cout << dis << endl;
    return 1;
}

//
int distance(int N, int C)
{
    int L = 1;
    int R = x[N-1] - x[0];
    int D, cows;
    while (L <= R){
        D = L + (R - L)/2;
        cows = C - 1;
        for (int i = 1, j = 0; i < N; i++){
            if (x[i] - x[j] >= D){
                j = i;
                cows--;
            }
            if (N - 1 - i < cows)
                break;
        }
        if (cows <= 0)
            L = D + 1;
        else
            R = D - 1;
    }
    return D;
}

/*
#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int n, c, a[100005];

int judge(int x)
{
	int i,s=1,p=a[0];
	for(i=1; i<n; i++)
	{
		if(a[i]-p>=x)
		{
			s++;
			p=a[i];
		}
	}
	return s;
}
int main()
{
	int i,j;
	cin >> n >> c;
	for(i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int l=0,r=a[n-1]-a[0];
	while(r>=l)
	{
		int mid=(l+r)>>2;
		if(judge(mid)>=c)
			l=mid+1;
		else
			r=mid-1;
	}
	cout << l-1 << endl;
	return 0;
}
*/
