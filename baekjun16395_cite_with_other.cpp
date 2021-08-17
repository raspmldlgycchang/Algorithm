//��ü ����� �¿��Ī�̴�
//�Ľ�Į�� �ﰢ���� ���װ���� ������ �ִٴ� ���� ������ ���鼭 �����ֱ淡 �� �¿��Ī���� ������ �غ��ٰ�
//�¿��Ī�̶� ���� �� ������ (x+1)^3 �̿��µ� (a+b)^n�̶�� �ϸ� a�� r��, b�� n-r�� �̴� ��쿡�� 
//r�� 0���� n���� ��� ��츦 ���� ���� �� ���� ����� �ǰ� �ᱹ N��° �ٿ��� N���� ���� ������ a�� r�� �̰��� b�� �ڵ����� n-r���� 
//������ ������ ����� nCr�� �����־�� �ϰ� �׸��� nCr�� nCn-r�� ���� ���� �¿��Ī�� �� �ۿ� ������
//����1ó�� ����� �����⿡
//����� ������ �־��� N��(1<=N<=30) ���� ��� �������� ������ r�� �̿��ؼ� �Ẹ�� N*(N-1)*...*(N-(r-1))/r! �� �Ǵµ�
//�̰� �������� �־��� k(1<=k<=N)���� ���� k��°�� ���� r�� ������ ���� �����Ƿ�(Ȥ�� ����2)
// N*(N-1)*...*(N-(p-1))/p!�� ������ָ� �ȴ�
#include<iostream>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;

	unsigned long long int binomial_coefficient=1;

	n--;
	k--;
	k = k < n - k ? k : n - k;//�� ���� �� ��
	

	for (int i = 0; i < k; i++) {
		binomial_coefficient *= (n - i);
	}

	for (int i = 1; i <= k; i++) {
		binomial_coefficient /= i;
	}
	printf("%lld\n\n", binomial_coefficient);

	for (int n = 1; n <= 7; n++) {//7��° �ٱ�����
		for (int k = 0; k <= n-1; k++) {//(n-1)��° �� �� ���
			binomial_coefficient = 1;
			for (int i= 0; i < k; i++) {
				binomial_coefficient *= ((n-1) - i);
			}
			for (int i = 1; i <= k; i++) {
				binomial_coefficient /= i;
			}
			printf("%lld\t", binomial_coefficient);
		}
		printf("\n");
	}
	
	printf("\n");
	//cout << binomial_coefficient;
	return 0;
}