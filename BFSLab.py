from collections import deque
N, M = map(int, input().split())
result = 0
graph = []
temp = [[0]*M for _ in range(N)]
#U R D L
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
for i in range(N):
    graph.append(list(map(int, input().split())))
#makeWall함수에서 bfs를 재귀호출해서
#bfs가 호출종료되기 전까지 temp의 해당 원소가 벽인 상태를 유지하고
#큐에서 빠지기 전까지
def BFS():
    queue = deque()
    #temp가 다 만들어지고 queue에 넣는 작업을 해야 하므로
    #bfs함수에 들어와서 큐에 넣는 작업을 해야 하고
    #큐도 정의를 bfs함수에서 한다
    #바이러스면 큐에 넣는다
    for i in range(N):
        for j in range(M):
            #큐에 전부다 append해두는이유는 어차피 다 같은 깊이이기 때문인데
            #이 문제는 단순히 바이러스가 있는 영역의 노드를 주변으로 다 퍼뜨리는 bfs라서
            #어떤 노드에 연결되서 bfs를 깊이에 따라 순차적으로 호출하는 것이 아니라
            #2이면 bfs를 수행하는 것이라서 같은 깊이의 노드를 여러개가 있는 것과 동일하다
            #따라서 먼저 2인 노드를 전부 넣어놓고 밑에서 네 방향으로 갈 때 bfs를 한다
            if temp[i][j]==2:
                queue.append((i,j))
    while queue:
        x,y = queue.popleft()
        #현재 빼내는 노드에대해서 네 방향 이동
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx <= -1 or nx >= N or ny <= -1 or ny >= M:
                continue
            if not visited[nx][ny] and temp[nx][ny]==0:
                #한 번 방문한 곳은 또 방문하면 안되니까(바이러스가 퍼지면 안되니까)
                #temp[nx][ny]==0인 경우만 퍼질 수 있으니까
                queue.append((nx,ny))
                visited[nx][ny] = True


    #BFS수행이 끝나고 visited가 False인 0을 세서 안전구역을 센다
    empty = 0
    for i in range(N):
        for j in range(M):
            # visited가 True인 0은 2인 노드가 bfs를 하면서 방문한 노드이다
            # 따라서 visited가 False인 원소도 조건에 추가해야 한다
            if temp[i][j]==0 and not visited[i][j]:
                empty+=1
    return empty
#재귀호출 함수
def makeWall(cnt):
    global result
    #3개의 벽을 다 세웠다면 BFS를 수행하고 makeWall함수호출이 끝나면
    #세 번째 원소가 끝나면 두번째 벽 원소에서 호출한 makeWall함수에서 0인 원소를 고르는데
    #이때 세번째 원소에 대해서 temp[i][j]=0으로 벽을 허무는 코드가 이미 실행되었기 때문에
    #for문을 써서 다음인덱스를 가져와야 하는 것이고
    #따라서 세번째 원소는 방금 벽으로 쓰이고 BFS를 수행하고 makeWall(3)에서
    #이 세번째 원소까지로 이루어진 temp배열로 이미 empty변수를 반환했고
    if cnt==3:
        empty = BFS()
        #현재 result와 비교해서 더 작은 값을 result에 넣어준다
        result = max(result, empty)
        return result


    # cnt가 3이 아니라면 벽을 더 세우고 계속 bfs를 호출한다
    for i in range(N):
        for j in range(M):
            #temp배열을 복사해서 받는거라 temp[i][j]==0인 곳에만 벽을 세워야 하는데
            #이것을 temp배열을 메인함수에서 graph클론 조건으로 걸었을 뿐이라서
            #여기서 다시한번 점검이 필요하다
            #첫번째와 두번째 벽의 원소로 해줄 애들은 이미 1로 바뀌어서
            #현재 makeWall재귀호출을 한 상태라서 여기에 안 걸린다
            if temp[i][j]==0:
                # 해당 칸에 벽을 세우고
                temp[i][j] = 1
                # 벽의 개수를 세야하므로 cnt를 증가시키고
                makeWall(cnt + 1)
                # 벽을 다시 허문다
                temp[i][j] = 0
cnt = 0
visited = [[False]*M for _ in range(N)]
for i in range(N):
    for j in range(M):
        if(graph[i][j]==0):
            #연구실 상태를 clone한다
            for k in range(N):
                for l in range(M):
                    temp[k][l] = graph[k][l]
            #벽으로 해줄 첫 원소는 메인함수에서 벽을 세워준다
            temp[i][j] = 1
            #벽을 한 개 방금 세웠으니까, 그리고 그 이후에 세워지는 벽은 makeWall재귀호출에서 cnt가 증가한다
            makeWall(1)
            temp[i][j] = 0
print(result)
