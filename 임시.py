from collections import deque
import sys
N, M = map(int, input().split())
graph = []
red = []
blue = []
empty = []
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
        if graph[i][j] == 'O':
            empty.append((i,j))
def bfs():
    ret = 987654321
    red_queue = deque()
    blue_queue = deque()
    empty_x, empty_y = empty[0]
    count = 0
    cur_red_x, cur_red_y = red[0]
    red_nx,red_ny = cur_red_x, cur_red_y
    visited_red[cur_red_x][cur_red_y] = True
    red_queue.append((cur_red_x,cur_red_y))
    cur_blue_x, cur_blue_y = blue[0]
    blue_nx, blue_ny = cur_blue_x, cur_blue_y
    visited_blue[cur_blue_x][cur_blue_y] = True
    blue_queue.append((cur_blue_x,cur_blue_y))
    while red_queue or blue_queue:
        if red_queue:
            cur_red_x, cur_red_y = red_queue.popleft()
        if blue_queue:
            cur_blue_x, cur_blue_y = blue_queue.popleft()
        for k in range(4):
            red_nx, red_ny = cur_red_x+dx[k], cur_red_y+dy[k]
            while(1):
                if graph[red_nx][red_ny] == '.':
                    red_nx += dx[k]
                    red_ny += dy[k]
                else:
                    if graph[red_nx][red_ny] == '#':
                        red_nx -= dx[k]
                        red_ny -= dy[k]
                    break

            blue_nx, blue_ny =cur_blue_x + dx[k], cur_blue_y + dy[k]
            while (1):
                if graph[blue_nx][blue_ny] == '.':
                    blue_nx += dx[k]
                    blue_ny += dy[k]
                    print('blue'+'(', blue_nx, blue_ny, ')')
                else:
                    if graph[blue_nx][blue_ny] == '#':
                        blue_nx -= dx[k]
                        blue_ny -= dy[k]
                    break


            if blue_nx == red_nx and blue_ny == red_ny:
                red_dist = abs(red_nx - cur_red_x)+abs(red_ny-cur_red_y)
                blue_dist = abs(blue_nx -cur_blue_x)+abs(blue_ny -cur_blue_y)
                if red_dist < blue_dist:
                    blue_nx, blue_ny = blue_nx - dx[k], blue_ny - dy[k]
                else:
                    red_nx, red_ny = red_nx - dx[k], red_ny - dy[k]

            #한 번의 기울임 이후 서로 다른 좌표에 들어간경우
            else:
                #이걸 백준에 제출하지는 않을 거라서 가독성을 위해서 else안에 다시 if와 else로 썼습니다
                if blue_nx == empty_x and blue_ny == empty_y:
                    print('실패')
                    ret = 0
                elif red_nx == empty_x and red_ny == empty_y and count<10:
                    print('성공')
                    ret = 1
                elif red_nx == empty_x and red_ny == empty_y and count>=10:
                    print('초과')
                    ret = -1
            #다음에 방문할 좌표가 모두 정해지면 red와 blue공의 큐에 다음 좌표를 넣어준다
            if not visited_red[red_nx][red_ny]:
                red_queue.append((red_nx, red_ny))
                count += 1
                visited_red[red_nx][red_ny] = True
            if not visited_blue[blue_nx][blue_ny]:
                blue_queue.append((blue_nx, blue_ny))
                visited_blue[blue_nx][blue_ny] = True
            if ret==0 or ret==-1 or ret==1:
                return ret
print(bfs())