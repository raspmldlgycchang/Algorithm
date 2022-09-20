#include <iostream>
#include <cmath>
using namespace std;
#define large_integer long long
#define number_of_digits long long

int getDigits(long long n)
{
	int digits = 0;

	if (n == 0)
		return digits - 1;
	else
	{
		n /= 10;
		digits++;
	}
}

int getMax(int u_digits, int v_digits)
{
	if (u_digits > v_digits)
		return u_digits;
	else
		return v_digits;
}

large_integer prod(large_integer u, large_integer v)
{
	large_integer x, y, w, z;

	int n, m;

	int u_digits = getDigits(u), v_digits = getDigits(v);

	n = getMax(u_digits, v_digits);

	if (u == 0 || v == 0)
		return 0;
	else if (n <= 2)
		return u * v;
	else
	{
		m = n / 2;
		x = u / pow(10, m); y = u % (int)pow(10, m);
		w = v / pow(10, m); z = v % (int)pow(10, m);
		return prod(x, w) * pow(10, 2 * m) +
			(prod(x, z) + prod(w, y)) * pow(10, m) +
			prod(x, z);
	}
}

int main(void)
{
	/*int i = 0, j = 0;
	int res[18] = { 0, };
	int n = 128;
	do
	{
		res[j++] = n % 2;
	} while (j&& (n = n / 2));

	for (int i = j-1; i>=0; i--)
	{
		printf("%d", res[i]);

	}*/

	long long a, b, result;

	cin >> a >> b;

	result = prod(a, b);

	cout << result << endl;

	return 0;
}