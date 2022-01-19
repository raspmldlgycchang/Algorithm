#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dpdfs(int sx, int sy) {//ù ���������� 0,0
	//L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == N - 1 && sy == M - 1)
		return 1;
	//�湮�� �ߴٸ� �� ��忡 ���� dfs�� ����Ǿ��ִ� �����̱� ������ �� �̻� �� ��忡 ���� dfs�� �������� �ʽ��ϴ�
	//��� dp���̺��� ���� �����ͼ� ������ ��� (sx,sy)���� �� �� �ִ� ����� ���� ���մϴ�
	// �׷����� dfs��ȯ���� dp[sx][sy]�� �����־�� ���� ��忡 ���� ��� �������� dfs�� ����˴ϴ�
	if (dp[sx][sy] == -1) {
		//�� ����(sx,sy)�� �湮�ߴٸ� ���������� True�� �湮�� ǥ���ϴµ�
		//dp������ dp���̺� ������ visited�迭�� �ʿ���� �ȴ�
		dp[sx][sy] = 0;
		// �� �������� �� �� �ִ� �����濡 ���ؼ� dfs�� �����Ѱ��� ��� ���ϸ�
		// ���� ����ó�� 3���� ��θ� �� ���� �˾Ƴ��� �ϹǷ� dfs�� �����մϴ�(�ڼ��� ������ ���� ��ũ�� �������������ּ���.)
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			if (graph[nx][ny] < graph[sx][sy])
				dp[sx][sy] += dpdfs(nx, ny);
			//�̹� �湮�� ������ ����� dp���̺� �� ���� ����Ǿ��־
			//�� ��쿣 dpdfs�� �������� �ʰ� dp���̺� ���� �����ϸ� �˴ϴ�
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