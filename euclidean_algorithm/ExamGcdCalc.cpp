#include"Gcd.h"
#include"GcdHandle.h"

int main(void)
{
	GcdHandle obj;

	int result = obj.operator()(48, 16);

	std::cout << "�ִ� ����� CalcResult : " << result << std::endl;

	return 0;
}