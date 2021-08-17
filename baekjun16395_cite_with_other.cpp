//전체 모양이 좌우대칭이다
//파스칼의 삼각형이 이항계수랑 관련이 있다는 것이 문제를 보면서 적혀있길래 왜 좌우대칭인지 생각을 해보다가
//좌우대칭이라서 순간 든 생각은 (x+1)^3 이였는데 (a+b)^n이라고 하면 a를 r번, b를 n-r번 뽑는 경우에서 
//r을 0부터 n까지 모든 경우를 적은 수가 각 항의 계수가 되고 결국 N번째 줄에는 N개의 항이 나오고 a를 r번 뽑고나면 b는 자동으로 n-r번이 
//뽑히기 때문에 계수는 nCr만 적어주어야 하고 그리고 nCr과 nCn-r이 같은 수라서 좌우대칭일 수 밖에 없었다
//사진1처럼 계수가 써지기에
//계수는 문제에 주어진 N과(1<=N<=30) 제가 방금 공식으로 설명한 r을 이용해서 써보면 N*(N-1)*...*(N-(r-1))/r! 이 되는데
//이걸 문제에서 주어진 k(1<=k<=N)으로 쓰면 k번째는 위의 r과 동일한 값을 가지므로(혹은 사진2)
// N*(N-1)*...*(N-(p-1))/p!를 출력해주면 된다
#include<iostream>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;

	unsigned long long int binomial_coefficient=1;

	n--;
	k--;
	k = k < n - k ? k : n - k;//더 작은 값 택
	

	for (int i = 0; i < k; i++) {
		binomial_coefficient *= (n - i);
	}

	for (int i = 1; i <= k; i++) {
		binomial_coefficient /= i;
	}
	printf("%lld\n\n", binomial_coefficient);

	for (int n = 1; n <= 7; n++) {//7번째 줄까지만
		for (int k = 0; k <= n-1; k++) {//(n-1)번째 줄 다 출력
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