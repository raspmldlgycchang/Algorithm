#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int graph[500][500];
int N, M;
int dp[500][500];
int dpdfs(int sx, int sy) {//첫 시작지점은 0,0
	//3방향 L R U D
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	if (sx == N-1  && sy == M-1)
		return 1;
	//dfs의 특성이기도 하지만 과정을 생각해보면
	//방문을 했다면 더 그 지점에서 파생되는 dfs는 안쪽 for문에서 이미 모두 수행이 된 상태라서
	//dp[sx][sy]==-1인 경우만 고려하면된다
	if (dp[sx][sy] == -1) {
		//방문했는 경우에 그 지점을 건너뛰는 것이 아니라
		// 그 지점에 몇 개의 갈래길이 있는지를 반환한다
		// 따라서 그 지점에 모든 길을 기록하는 것이 아니라
		// 그 지점에서 몇 개로 갈 수 잇는지를 기록한다
		// 그럴려면 dfs를 sx에 더해주어야 한다
		// 요약해서 이 부분의 역할을 설명하면
		//이전에 저장된 값을 가져올 건데 dfs를 수행하면 그만큼 몇 갈래인지가 더해집니다
		//그럴려면 dfs가 반환하는 값이 현재의 지점에 대해서 dp값을 반환을 해야 합니다
		
		//따라서 먼저 이 지점을 방문(sx,sy)했다면 원래같으면 True로 방문을 표시하는데
		//dp에서는 dp테이블 만으로 visited배열은 필요없게 된다
		dp[sx][sy] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx <= -1 || nx >= N || ny <= -1 || ny >= M)
				continue;
			//만약 하나라도 true를 반환하면 dfs를 수행하고
			//아니면 false를 반환해서 위로 올라간다
			//세 방향 중에서 작은 값을 가진 애가 있어서 더방문해야 되면 몇 갈래 길이 있는지 저장하다
			if (graph[nx][ny] < graph[sx][sy])
				dp[sx][sy] += dpdfs(nx, ny);
			//이미 방문한 지점의 경우라면 dp테이블에 그 값이 저장되어있어서
			//이 경우엔 dpdfs를 수행하지 않고 dp테이블 값을 저장하면 되므로
			//dpdfs를 호출하는 것입니다

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