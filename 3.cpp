#include<iostream>
#pragma warning(disable: 4819)
using namespace std;
int main(void)
{
	int n = 1, X;
	cin >> X;
	while (1) {
		if (X <= (n + n * n) / 2)	break;
		n++;
	}
	int temp = X-n*(n-1)/2;//X가 n째줄에서 temp번째인지(첫번째가 temp=1)
	
	(!(n % 2)) ? (cout << 1+(temp-1) << "/" << n - (temp-1)) : (cout << n - (temp-1) << "/" << 1 + (temp-1));
	return 0;
}