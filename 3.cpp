#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	double result = T * T / 4.0 + 0.5;
	//출처(반올림 구현): 출처1
	cout << int(result) << "\n";
	cout << (int)result;

	float Float_var = 3.0E-47;//3.0e-47
	cout << "very tiny value" << Float_var;
	return 0;
}