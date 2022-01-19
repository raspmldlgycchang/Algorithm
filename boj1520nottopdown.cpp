#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dpdfs(int sx, int sy) {//첫 시작지점은 0,0
	//L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == N - 1 && sy == M - 1)
		return 1;
	//방문을 했다면 그 노드에 대한 dfs가 저장되어있는 상태이기 때문에 더 이상 그 노드에 대한 dfs는 수행하지 않습니다
	//대신 dp테이블의 값을 가져와서 현재의 노드 (sx,sy)에서 갈 수 있는 경우의 수를 더합니다
	// 그럴려면 dfs반환값을 dp[sx][sy]에 더해주어야 현재 노드에 대한 모든 갈래길의 dfs가 저장됩니다
	if (dp[sx][sy] == -1) {
		//이 지점(sx,sy)을 방문했다면 원래같으면 True로 방문을 표시하는데
		//dp에서는 dp테이블 만으로 visited배열은 필요없게 된다
		dp[sx][sy] = 0;
		// 그 지점에서 갈 수 있는 갈래길에 대해서 dfs를 수행한값을 모두 더하면
		// 문제 예시처럼 3개의 경로를 한 번에 알아내야 하므로 dfs를 수행합니다(자세한 설명은 위의 링크된 포스팅참고해주세요.)
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			if (graph[nx][ny] < graph[sx][sy])
				dp[sx][sy] += dpdfs(nx, ny);
			//이미 방문한 지점의 경우라면 dp테이블에 그 값이 저장되어있어서
			//이 경우엔 dpdfs를 수행하지 않고 dp테이블 값을 저장하면 됩니다
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