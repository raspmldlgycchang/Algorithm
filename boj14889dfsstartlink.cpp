#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int graph[20][20];
vector<int> start;
vector<int> link;
vector<int> total;
typedef struct addOnePair
{
	int m_member1;
	int m_member2;
	addOnePair(int a_member1, int a_member2)
		: m_member1(a_member1), m_member2(a_member2)
	{
	}
}Pair;
vector<Pair> start_final;
vector<Pair> link_final;
vector<int> start_pick;
vector<int> link_pick;
int N;
int result = 987654321;//20억=2000백만>987654321
//조합은 dfs와 유사하게 현재 경우에 대해서 nCr에서 r이 몇인지를 재귀호출로 알려주고
//r이 0이 되면 함수를 종료합니다
//output배열이 필요하고 input배열이 필요하고 inverse reduction tree의 경우
//stride로 업데이트할 shared memory를 알아야 해
//dfs함수를 만들어낸 부분코드
//Combination함수코드출처: https://ansohxxn.github.io/algorithm/combination/
void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
	//shared memory정의
	//여기선 global index가 필요
	//shared memory초기화
	//뒤에서부터 stride씩 자르면서 앞부분에 더해준다
	if (r == 0)
	{
		for (int i = 0; i < comb.size(); i++)
			cout << comb[i] << " ";
		cout << endl;
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		//arr[depth]를 뽑은 경우
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		//arr[depth]안뽑은경우
		Combination(arr, comb, r, index, depth + 1);
	}
}

void Combination_aftermaketeam(int r, int index, int depth)
{
	if (r == 0)
	{
		for (int i = 0; i < start_pick.size(); i++) {
			if ((i + 1) % 2 == 0) {
				start_final.push_back(Pair(start_pick[i], start_pick[i + 1]));
				//여기서 link_final도 만들어야 함
				for (int j = 0; j < N; j++) {
					if (j != i) {
						link_pick.push_back(total[j]);
					}
				}

			}
		}

		//link팀 전체 조합 경우의수구하기
		for (int i = 0; i < link_pick.size(); i++) {
			if ((i + 1) % 2 == 0) {
				link_final.push_back(Pair(link_pick[i], link_pick[i + 1]));
			}
		}
	}
	else if (depth == start.size()) {
		return;
	}
	else {
		//arr[depth]를 뽑은 경우
		start_pick[index] = start[depth];
		Combination_aftermaketeam(r - 1, index + 1, depth + 1);

		//arr[depth]안뽑은경우
		Combination_aftermaketeam(r, index, depth + 1);
	}
}
void dfs()
{
	int start_sum=0, link_sum = 0;
	//조합으로 임의 2명선택하는데(nCr에서 r=2)
	Combination_aftermaketeam(2, 0, 0);//재귀호출함수
	//아래 for문에서 어차피 N/2로 두 벡터의 크기가 동일해서 한 개의 벡터로 두 개를 가져온다
	for (vector<Pair>::iterator iter = start_final.begin(); iter != start_final.end(); iter++) {
		start_sum = 0, link_sum = 0;
		Pair cur = start_final.front();
		start_final.pop_back();
		int start_first = cur.m_member1;
		int start_second = cur.m_member2;

		cur = link_final.front();
		link_final.pop_back();
		int link_first = cur.m_member1;
		int link_second = cur.m_member2;

		link_sum += link_first + link_second;
		start_sum += start_first + start_second;

		result = min(result, abs(start_sum - link_sum));
	}

	return;
}
/*void makeTeam() {
	//스타트팀N/2명 or 링크팀N/2명선택이 끝나면 dfs함수를 호출
	if (start.size() ==N/2) {
		//링크팀에 학생넣기는 
		dfs();
	}
	//그 전까지는 팀 뽑기
	Combination_aftermaketeam(2, 0, 0);
	//남은 애들은 그 번호를 제외한 애들
	//for문에서 전체 학생 돌면서 start아닌 애들을 link에 넣는다
}
*/

int main()
{
	//vector<int> vec = { 1,2,3,4,5 };
	//int r = 3;
	//vector<int> comb(r);

	//Combination(vec, comb, r, 0, 0);

	cin >> N;

	for (int i = 0; i < N; i++)
		total.push_back(i);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	dfs();

	cout << result << endl;
	//현재 나누는수(16)로 나누면 나머지는 (0x00)0~나누는수-1(0x0F-1)까지다
	/*do {
		arr[i] = (char)(var & 0x0F);//나머지는 0~15이므로 비트연산AND를 이용한다
	} while (i++ && (var=var >> 4));//16씩나누어주면서 var을 수정한다
	*/
	//비트마스크
	//16전까지의 수를 0x0001<<1 0x0010<<1  0x0100<<1 0x1000로 하므로
	//이코드는 {T,F,F,F}로 만들수있는 모든 순열의 경우의수와 동일
	//주어진mask전까지의 수가 될 때까지 1비트씩 이동해서 안쪽for문에서는 mask수에서 한 비트만 값이 1인 경우,
	//그 다음의 바깥 for문에서 1개수를 증가시켜가며 결국 그 경우의수가 바깥쪽for문에 있는 1의 개수로 T개수를 정할 때
	//다른 비트값들에 해당하는(0) 것들은 F로 해서 그것으로 만들 수 있는 모든 순열의 수입니다

	return 0;
}
//256씩 곱하면서 수를 만들고 256으로 나눈 나머지를 출력한다
//256=2^8=2^8*1+나머지0=0x00000100=16^2*1+나머지0