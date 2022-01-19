#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dpdfs(int sx, int sy) {//ù ���������� 0,0
	//3���� L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == N-1  && sy == M-1)
		return 1;
	//dfs�� Ư���̱⵵ ������ ������ �����غ���
	//�湮�� �ߴٸ� �� �� �������� �Ļ��Ǵ� dfs�� ���� for������ �̹� ��� ������ �� ���¶�
	//dp[sx][sy]==-1�� ��츸 ����ϸ�ȴ�
	if (dp[sx][sy] == -1) {
		//�湮�ߴ� ��쿡 �� ������ �ǳʶٴ� ���� �ƴ϶�
		// �� ������ �� ���� �������� �ִ����� ��ȯ�Ѵ�
		// ���� �� ������ ��� ���� ����ϴ� ���� �ƴ϶�
		// �� �������� �� ���� �� �� �մ����� ����Ѵ�
		// �׷����� dfs�� sx�� �����־�� �Ѵ�
		// ����ؼ� �� �κ��� ������ �����ϸ�
		//������ ����� ���� ������ �ǵ� dfs�� �����ϸ� �׸�ŭ �� ���������� �������ϴ�
		//�׷����� dfs�� ��ȯ�ϴ� ���� ������ ������ ���ؼ� dp���� ��ȯ�� �ؾ� �մϴ�
		
		//���� ���� �� ������ �湮(sx,sy)�ߴٸ� ���������� True�� �湮�� ǥ���ϴµ�
		//dp������ dp���̺� ������ visited�迭�� �ʿ���� �ȴ�
		dp[sx][sy] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			//���� �ϳ��� true�� ��ȯ�ϸ� dfs�� �����ϰ�
			//�ƴϸ� false�� ��ȯ�ؼ� ���� �ö󰣴�
			//�� ���� �߿��� ���� ���� ���� �ְ� �־ ���湮�ؾ� �Ǹ� �� ���� ���� �ִ��� �����ϴ�
			if (graph[nx][ny] < graph[sx][sy])
				dp[sx][sy] += dpdfs(nx, ny);
			//�̹� �湮�� ������ ����� dp���̺� �� ���� ����Ǿ��־
			//�� ��쿣 dpdfs�� �������� �ʰ� dp���̺� ���� �����ϸ� �ǹǷ�
			//dpdfs�� ȣ���ϴ� ���Դϴ�

			//cout << nx << " , " << ny << " : " << graph[nx][ny] << endl;
		}
	}
	return dp[sx][sy];
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = -1;
		}
	}
	cout << dpdfs(0, 0) << endl;
	return 0;
}