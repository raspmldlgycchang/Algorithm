from collections import deque
import sys
N, M = map(int, input().split())
graph = []
red = []
blue = []
visited_red = [[False]*M for _ in range(N)]
visited_blue = [[False]*M for _ in range(N)]
#U R D L
dx = [1,0,-1,0]
dy = [0,1,0,-1]
result = 987654321
graph = [input() for _ in range(N)]
for i in range(N):
    for j in range(M):
        if graph[i][j]=='R':
            red.append((i,j))
        if graph[i][j]=='B':
            blue.append((i,j))
def bfs():
    count = 0
    blue_queue = deque()
    red_queue = deque()
    blue_x,blue_y = blue[0]
    blue_queue.append((blue_x,blue_y))
    red_x,red_y = red[0]
    red_queue.append((red_x,red_y))
    for k in range(4):
        #빈칸위치 저장할 리스트
        empty = []
        #blue와 red는 같은 방향으로 움직이기에 하나의 for문에서 통제
        red_nx, red_ny = red_x+dx[k], red_y+dy[k]
        blue_nx,blue_ny = blue_x+dx[k], blue_y+dy[k]
        #red와 blue를 모두 지금 진행하는 기울이기 한 번에서 서로가 없다고 생각하고 한 다음에
        #아래에서 while문 나가서 nx,ny를 둘을 비교해서 같은 nx,ny이면 더 적게 이동한 애가 그 위치에 있도록
        #다른 애는 그 전의 한 칸 전에 있도록
        #하나의 기울임 작업에서 하는 작업
        #blue와 red에 대해서 각각 한다
        #4개의 방향 중에서 빈칸이 나오면 그 방향으로 계속 가는 걸 진행
        if graph[red_nx][red_ny] == '.':
            while(0<red_nx<N-1 and 0<red_ny<M-1):
                if not visited_red[red_nx][red_ny] and graph[red_nx][red_ny]=='.':
                    red_nx,red_ny = red_nx+dx[k], red_ny+dy[k]
                elif graph[red_nx][red_ny]=='O':
                    count += 1
                    empty.append((red_nx, red_ny))
                    break
                else:
                    break
            red_queue.append((red_nx,red_ny))
            visited_red[red_nx][red_ny]= True
            count += 1
            print('count'+str(count))
            #빨간공 파란공의 위치 같은지 점검을 while문을 나와서 하고
            #한 방향의 기울임에 있어서 끝까지 이동하는데 그 중에 빈칸이 있으면 break랑 count+1을 하고
            #그 위치를 반환한뒤 nx,ny가 빨, 파이 겹치는지 확인하고
        if graph[blue_nx][blue_ny] == '.':
            while (0 < blue_nx < N - 1 and 0 < blue_ny < M - 1):
                if not visited_blue[blue_nx][blue_ny] and graph[blue_nx][blue_ny] == '.':
                    blue_nx, blue_ny = blue_nx + dx[k], blue_ny + dy[k]
                elif graph[blue_nx][blue_ny] == 'O':
                    empty.append((blue_nx,blue_ny))
            blue_queue.append((blue_nx, blue_ny))
            visited_blue[blue_nx][blue_ny] = True
        #빨간공과 파란공이 같은 줄이였다면(이동후에 위치가 같다) 빨간공보다 더 적게 이동했으면 실패
        #더 많이 이동했다면 성공

        #같은 공간에 빨간색공과 파란색공이 함께 존재한다면 더 적게 움직인 애를 그 위치에
        #더 많이 움직인 애를 그 위치보다 하나 작게 한 위치에 넣어준다
        if blue_nx==red_nx and blue_ny==red_ny:
            #현재 큐에 저장된 것은 지금의 같은 지점이므로 큐에서 가장 나중에서 한 칸 이전의 원소가
            #현재의 같은 지점 이전에 각 공의 지점이므로 그 지점과 현재 지점과의 차이를 구한다
            blue_former_x, blue_former_y = blue_queue[len(blue_queue)-2]
            red_former_x, red_former_y = red_queue[len(red_queue)-2]
            if abs(blue_nx-blue_former_x)<abs(red_nx-red_former_x) or abs(blue_ny-blue_former_y)<abs(red_ny-red_former_y):
                red_nx, red_ny = red_nx-dx[k], red_ny-dy[k]
                red_queue.popleft()
                red_queue.append((red_nx, red_ny))
            else:
                blue_nx, blue_ny = blue_nx-dx[k], blue_ny-dy[k]
                blue_queue.popleft()
                blue_queue.append((blue_nx, blue_ny))
        #nx,ny가 빨, 파가 다른데 빨간공이 빈칸에 들어간 경우라면 성공반환
        #nx,ny에는 빈칸이전의 노드가 담겨있으므로 차이가 더 큰 얘가 그 칸에 못 들어가는 얘
        elif len(empty)==2:
            e_x, e_y = empty[0]
            if(abs(e_x-blue_nx)<abs(e_x-red_nx)) or (abs(e_y-blue_ny)<abs(e_y-red_ny)):
                return 0#실패반환
            #빨간색이 구멍까지 더 적게 이동함
            #count가 10보다 작은지를 고려해야 한다
            #그리고 현재 저장된 count랑 비교해야 한다
            elif count<10:
                return count#성공반환
            #빨간색이 구멍까지 더 적게 이동함
            else:#count가 10이상임
                return -1
        #빈칸에 어느 하나만 들어간 경우
        elif len(empty)==1:
            if count<10:
                return 'count'+str(count)
            else:
                return -1
print(bfs())