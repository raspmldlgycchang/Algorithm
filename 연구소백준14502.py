from collections import deque
N, M = map(int, input().split())
INF = 987654321
result = INF
graph = []
temp = [[0]*M for _ in range(N)]
#L R U D
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
for i in range(N):
    graph.append(list(map(int, input().split())))
#makeWall함수에서 bfs를 재귀호출해서
#bfs가 호출종료되기 전까지 temp의 해당 원소가 벽인 상태를 유지하고
#큐에서 빠지기 전까지
def BFS(x,y):
    queue = deque()
    visited[x][y] = True
    while queue:
        x,y = queue.popleft()
        if temp[x][y] == 2:
            #현재 빼내는 노드에대해서 네 방향 이동
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if not visited[nx][ny]:
                #한 번 방문한 곳은 또 방문하면 안되니까(바이러스가 퍼지면 안되니까)
                    if nx <= -1 or nx >= N or ny <= -1 or ny >= M:
                        return False
                    if not temp[nx][ny]:#temp[nx][ny]==0인 경우만 퍼질 수 있으니까
                        queue.append((nx,ny))
                        visited[nx][ny] = True

    #BFS수행이 끝나고 visited가 False인 0을 세서 안전구역을 센다
    empty = 0
    for i in range(N):
        for j in range(M):
            if temp[i][j]==0 and not visited[i][j]:
                empty+=1
    return empty
#재귀호출 함수
def makeWall(cnt):
    global result
    if cnt==3:
        empty = BFS(0,0)
        #현재 result와 비교해서 더 작은 값을 result에 넣어준다
        result = min(result, empty)
        return result


    # cnt가 3이 아니라면 벽을 더 세우고 계속 bfs를 호출한다
    for i in range(N):
        for j in range(M):
            # 해당 칸에 벽을 세우고
            temp[i][j] = 1
            # 벽의 개수를 세야하므로 cnt를 증가시키고
            makeWall(cnt + 1)
            # 벽을 다시 허문다
            temp[i][j] = 0


visited = [[False]*M for _ in range(N)]
cnt = 0
for i in range(N):
    for j in range(M):
        if(graph[i][j]==0):
            #연구실 상태를 clone한다
            for k in range(N):
                for l in range(M):
                    temp[k][l] = graph[k][l]
            #temp[i][j] = 1
            makeWall(1)
            #temp[i][j] = 0
print(result)
