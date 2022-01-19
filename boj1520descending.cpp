#include<iostream>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dfs(int sx, int sy) {//첫 시작지점은 N-1, M-1
	//L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == 0 && sy == 0)
		return 1;
	if (dp[sx][sy] == -1) {
		// 그 지점에 dfs호출을 통해서 dfs호출횟수가 재귀호출을 통해서 노드를 따라서 올라가면서 저장된다
		dp[sx][sy] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			if (graph[nx][ny] >= graph[sx][sy])
				dp[sx][sy] += dfs(nx, ny);
			//이미 방문한 지점의 경우라면 dp테이블에 그 값이 저장되어있어서
			//이 경우엔 그 노드에 대해서는 dfs를 더 이상 수행하지 않고 dp테이블 값을 저장합니다
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