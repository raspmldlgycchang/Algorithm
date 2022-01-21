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
int result = 987654321;//20��=2000�鸸>987654321
//������ dfs�� �����ϰ� ���� ��쿡 ���ؼ� nCr���� r�� �������� ���ȣ��� �˷��ְ�
//r�� 0�� �Ǹ� �Լ��� �����մϴ�
//output�迭�� �ʿ��ϰ� input�迭�� �ʿ��ϰ� inverse reduction tree�� ���
//stride�� ������Ʈ�� shared memory�� �˾ƾ� ��
//dfs�Լ��� ���� �κ��ڵ�
//Combination�Լ��ڵ���ó: https://ansohxxn.github.io/algorithm/combination/
void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
	//shared memory����
	//���⼱ global index�� �ʿ�
	//shared memory�ʱ�ȭ
	//�ڿ������� stride�� �ڸ��鼭 �պκп� �����ش�
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
		//arr[depth]�� ���� ���
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		//arr[depth]�Ȼ������
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
				//���⼭ link_final�� ������ ��
				for (int j = 0; j < N; j++) {
					if (j != i) {
						link_pick.push_back(total[j]);
					}
				}

			}
		}

		//link�� ��ü ���� ����Ǽ����ϱ�
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
		//arr[depth]�� ���� ���
		start_pick[index] = start[depth];
		Combination_aftermaketeam(r - 1, index + 1, depth + 1);

		//arr[depth]�Ȼ������
		Combination_aftermaketeam(r, index, depth + 1);
	}
}
void dfs()
{
	int start_sum=0, link_sum = 0;
	//�������� ���� 2�����ϴµ�(nCr���� r=2)
	Combination_aftermaketeam(2, 0, 0);//���ȣ���Լ�
	//�Ʒ� for������ ������ N/2�� �� ������ ũ�Ⱑ �����ؼ� �� ���� ���ͷ� �� ���� �����´�
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
	//��ŸƮ��N/2�� or ��ũ��N/2������ ������ dfs�Լ��� ȣ��
	if (start.size() ==N/2) {
		//��ũ���� �л��ֱ�� 
		dfs();
	}
	//�� �������� �� �̱�
	Combination_aftermaketeam(2, 0, 0);
	//���� �ֵ��� �� ��ȣ�� ������ �ֵ�
	//for������ ��ü �л� ���鼭 start�ƴ� �ֵ��� link�� �ִ´�
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
	//���� �����¼�(16)�� ������ �������� (0x00)0~�����¼�-1(0x0F-1)������
	/*do {
		arr[i] = (char)(var & 0x0F);//�������� 0~15�̹Ƿ� ��Ʈ����AND�� �̿��Ѵ�
	} while (i++ && (var=var >> 4));//16���������ָ鼭 var�� �����Ѵ�
	*/
	//��Ʈ����ũ
	//16�������� ���� 0x0001<<1 0x0010<<1  0x0100<<1 0x1000�� �ϹǷ�
	//���ڵ�� {T,F,F,F}�� ������ִ� ��� ������ ����Ǽ��� ����
	//�־���mask�������� ���� �� ������ 1��Ʈ�� �̵��ؼ� ����for�������� mask������ �� ��Ʈ�� ���� 1�� ���,
	//�� ������ �ٱ� for������ 1������ �������Ѱ��� �ᱹ �� ����Ǽ��� �ٱ���for���� �ִ� 1�� ������ T������ ���� ��
	//�ٸ� ��Ʈ���鿡 �ش��ϴ�(0) �͵��� F�� �ؼ� �װ����� ���� �� �ִ� ��� ������ ���Դϴ�

	return 0;
}
//256�� ���ϸ鼭 ���� ����� 256���� ���� �������� ����Ѵ�
//256=2^8=2^8*1+������0=0x00000100=16^2*1+������0