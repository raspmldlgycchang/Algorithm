#include<iostream>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dfs(int sx, int sy) {//ù ���������� N-1, M-1
	//L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == 0 && sy == 0)
		return 1;
	if (dp[sx][sy] == -1) {
		// �� ������ dfsȣ���� ���ؼ� dfsȣ��Ƚ���� ���ȣ���� ���ؼ� ��带 ���� �ö󰡸鼭 ����ȴ�
		dp[sx][sy] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			if (graph[nx][ny] >= graph[sx][sy])
				dp[sx][sy] += dfs(nx, ny);
			//�̹� �湮�� ������ ����� dp���̺� �� ���� ����Ǿ��־
			//�� ��쿣 �� ��忡 ���ؼ��� dfs�� �� �̻� �������� �ʰ� dp���̺� ���� �����մϴ�
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
	cout << dfs(N-1, M-1) << endl;
	return 0;
}