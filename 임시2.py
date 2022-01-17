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
    returnval = 987654321
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
        #for문으로 상하좌우중에 한 번의 기울임으로 이동이 완료된 후에
        #queue에 push하는 작업을 했는데 이것의 작업으로 가장 나중에 들어간 좌표를ㄹ pop한다
        #그리고 점검해서 여기서 return유무결정
        if cur_blue_x == empty_x and cur_blue_y == empty_y:
            print('실패')
            returnval = 0
            #break#python은 return 을 함수에서 while문 밖에서 하면 return outside function에러납니다
            return returnval
        elif cur_red_x == empty_x and cur_red_y == empty_y and count < 10:
            print('성공')
            returnval = 1
            #break
            return returnval
        elif cur_red_x == empty_x and cur_red_y == empty_y and count >= 10:
            print('초과')
            returnval = -1
            #break
            return returnval
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
            #다음에 방문할 좌표가 모두 정해지면 red와 blue공의 큐에 다음 좌표를 넣어준다
            if not visited_red[red_nx][red_ny]:
                red_queue.append((red_nx, red_ny))
                count += 1
                visited_red[red_nx][red_ny] = True
            if not visited_blue[blue_nx][blue_ny]:
                blue_queue.append((blue_nx, blue_ny))
                visited_blue[blue_nx][blue_ny] = True

print(bfs())