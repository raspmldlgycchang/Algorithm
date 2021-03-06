//좌측 페이지부터 페이지숫자(4페이지면 4페이지, 29페이지면 29페이지)가 적히고 우측 페이지는 N/2이후의 숫자들로 페이지숫자가 적힌다
//좌측 페이지의 마지막(안쪽 페이지가 된다) paperNum은 N/4
//우측, 좌측 안쪽 페이지의 paperNum은 N/2에서 -2 연산을 몇 번 하였느냐에 따라 N/4 - 몇 번으로 구해준다
//바깥쪽 페이지 숫자는 안쪽 페이지에 연속된 숫자로 출력

//좌측 안쪽 페이지 마지막과 우측 페이지 안쪽 페이지 시작을 2*N/4-2*0 과 2*N/4+1 + 2*0으로 하고
//젤 처음 좌측 안쪽 페이지는 (-2연산)을 N/2 - 1번 하므로 좌측 안쪽 페이지 마지막 paperNum이 N/4 - N/2 - 1 이 된다
//따라서 입력된 P가 몇 번째 페이지인지를 계산하는 방법은 N/2 - 2*i(0<=i<=N/2-1) 의 안쪽 좌측 페이지, N/2+1 +2*i 의 안쪽 우측 페이지, 연속되는 페이지들은
//안쪽 좌측 페이지 -1 과 우측 안쪽 페이지 +1 에 해당하는지 모두 검사를 해보고(for문에서 각 i마다 4번의 검사) P와 같은 페이지가 나오면 방금 언급한
//페이지들을 모두 출력해주면 된다

#include<iostream>
using namespace std;
int main(void)
{
	int N, P;
	cin >> N;

	int paperNum;
	//%연산과 /연산활용하여 위에서 생각한 것을 덧붙여 생각해보자.
	//먼저 안쪽 페이지들끼리 같은 paperNum이 나오도록 한다
	//사진 추가
	//이를 위해 %(N%2)연산결과가 같게 나오게 하기 위해 다음으로 유도를 한다
	//N을 %(N/2) 연산하면 P < N/2인 페이지는 N/2-2*i가 나오고 N/2면 0이 나오고
	//P > N/2인 페이지는 1 + 2*i 를 N/2로 나눈 나머지가 나오는데 N/2 + 2*i + 1은 N보다 작거나 같으므로 2*i+1이 그대로 출력된다
	//그래서 바로 위에서 구한 것을 pageNum이라는 페이지 숫자(paperNum과다름)에 저장하여
	//이것을 P < N/2인 페이지는 pageNum를 그대로 사용하고 P==N/2인 페이지는 N/2를 더해주고
	//P >N/2인 페이지는 N/2 + 1이 우측안쪽 페이지의 시작 페이지의 pageNum이므로, N/2에 2*i+1 만큼(0<=i<=N/2-1) 증가한 pageNum을 가지고 있다
	//paperNum은 좌측 안쪽 페이지는 pageNum/2로, 우측 안쪽 페이지는 +1은 공통이므로 %2 연산을 통해 짝,홀수로 해결하고,
	//N - N/2, N - (N/2-2*1), N-(N/2-2*2)..., => (N- 같은 paperNum에 놓인 좌측 안쪽 페이지의 pageNum) == (N- i가 같은 pageNum을 가지는 좌측 안쪽 페이지의 pageNum)
	//처음부터 i가 같은 pageNum인 좌,우측 안쪽 페이지들의 paperNum을 똑같이 놓아보기 위해 배열을 완성해놓고 P와 N을 검사하는 방식으로 해보자
	const int m_max_len = 1001;
	int paperNumArr[m_max_len] = {0,};
	
	while (N) {
		for (int i = 0; i < N / 4; i++) {//paperNum은 1부터 N/4까지 존재하므로
			paperNumArr[N / 2 - 2 * i] = (N / 2 - 2 * i) / 2;//pageNum/2에 해당
			paperNumArr[N - (N / 2 - 2 * i) + 1] = (N / 2 - 2 * i) / 2;

		}
		for (int i = N / 4 - 1; i >= 0; i--) {
			printf("%dpage %dpage 의 pageNum : %d %d\n", N / 2 - 2 * i, N - (N / 2 - 2 * i) + 1, paperNumArr[N/2-2*i], paperNumArr[N-(N/2-2*i)+1]);
		}
		printf("\n");
		cin >> P;
		for (int i = N/4-1; i>=0 ; i--) {
			if (P == N / 2 - 2 * i - 1) {
				//좌측 바깥쪽 페이지: 좌측 안쪽 페이지-1
				//좌,우측 안쪽 페이지는 i를 이용해서 하나의 paperNum값으로 초기화->초기화한 값을 그대로 쓴다
				//우측 바깥쪽 페이지: 우측 안쪽 페이지+1
				//pageNum == 2*paperNum(좌측 안쪽 페이지)
				cout << "N :" << N << "P :" << P << "\n";
				cout << paperNumArr[N / 2 - 2 * i]*2 << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1 << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1 + 1;
				break;
			}
			else if (P == N/2 - 2*i){
				cout << "N :" << N << "P :" << P << "\n";
				//pageNum == 2*paperNum(좌측 안쪽 페이지)
				cout << 2*paperNumArr[N / 2 - 2 * i] -1 << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1 << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1 + 1;
				break;
			}
			else if (P == N - (N / 2 - 2 * i) + 1) {
				cout << "N :" << N << "P :" << P << "\n";
				cout << 2 * paperNumArr[N / 2 - 2 * i] - 1 << " " << 2 * paperNumArr[N / 2 - 2 * i] << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1 + 1;
				break;
			}
			else if(P == N - (N/2 - 2*i) +1){
				cout << "N :" << N << "P :" << P << "\n";
				cout << 2 * paperNumArr[N / 2 - 2 * i] - 1 << " " << 2 * paperNumArr[N / 2 - 2 * i] << " " << N - 2 * paperNumArr[N / 2 - 2 * i] + 1;
				break;
			}
			else {
				continue;
			}
			
		}
		cout << "\n";
		//이렇게 구현해야 하는 방법은 위에서 언급한 블로거님의 코드를 통해서 알아낸 방법이다
		//cin >> N을 통해 받은 결과가 미리 저장해둔 배열에 이미 저장이 되어있으므로 그 N에 따라 배열이 결정되므로 N을 매번 새로 받아야 한다.
		//이 때 마지막에 받는 이유는 역시 위의 블로그 포스팅과 같은 이유이다
		//while문에서 처음에 N을 검사하도록 하기 때문에 미리 N을 받지만 백준 문제의 입력에서 N 이후에는 P를 받도록 했기 때문에 처음에 받고 또 받는다면
		//원하는입력이 아니다, 그리고 다음 루프에서 N을 검사하기전 이전 루프에서 N을 받아놔야 검사가 가능하다
		cin >> N;
	}
	return 0;
}