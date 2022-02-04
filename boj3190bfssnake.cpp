#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int graph[100][100];
int plan[10000][2];
int N, K, L;
int bfs(int sx, int sy)
{
	queue<int> q;
	int visited[100][100] = { 0, };
	//LR
	int dx[] = { 0,0};
	int dy[] = { -1,1};
	int i;
	char move_types[] = { 'L', 'D' };
	for (i = 0; i < L; i++) {
		int nx=0, ny=0;
		for (int k = 0; k < 2; k++) {
			if (plan[i][1] == move_types[i]) {
				nx = sx + dx[i];
				ny = sy + dy[i];
			}
		}
		if (nx <= -1 || nx >= N || ny <= -1 || ny >= N)
			continue;
		if ((nx == 0 && ny == 0) || (nx == N - 1 && ny == 0) || (nx == 0 && ny == N - 1) || (nx == N - 1 && ny == N - 1))
			return plan[i][0];
		if (graph[nx][ny])
			graph[nx][ny] = 0;
		else if (graph[nx][ny] == 0) {
			sx = nx;
			sy = ny;
		}
	}
	return 0;
}
int main()
{
	cin >> N;
	cin >> K;
	int row, col;
	char dir=0;
	for (unsigned int i = 0; i < 3; i++) {
		cin >> row >> col;
		graph[row][col] = 1;
	}
	cin >> L;
	for (unsigned int i = 0; i < L; i++){
		scanf("%d", &plan[i][0]);
		scanf("%c", &dir);
		rewind(stdin);
		plan[i][1] = dir;
	}
	cout << bfs(0,1) << endl;
	return 0;
}