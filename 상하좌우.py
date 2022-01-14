
#n을 받고
n = int(input())
#현재위치를 지정하고
x, y= 1,1
#공백을 기준으로 입력을 받고
plans = input().split()
#dx와dy를 지정
move_types = ['L', 'R', 'U', 'D']
dx = [1,0,-1,0]
dy = [0,1,0,-1]
#n만큼 for문에서
for plan in plans:
    for i in range(len(move_types)):
        if move_types[i] == plan:
            nx = x+dx[i]
            ny = y+dy[i]
    if nx<1 or ny<1 or nx>n or nx>n:
        continue
    x,y = nx, ny
#결과출력
print(x,y)