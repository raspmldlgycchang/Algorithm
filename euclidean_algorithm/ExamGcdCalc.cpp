#include"Gcd.h"
#include"GcdHandle.h"

int main(void)
{
	GcdHandle obj;

	int result = obj.operator()(48, 16);

	std::cout << "최대 공약수 CalcResult : " << result << std::endl;

	return 0;
}