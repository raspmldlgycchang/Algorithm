N,M = map(int, input().split())
INF = 987654321
result = INF
graph = []
for i in range(N):
    graph.append(list(map(int, input().split())))
house = []
chicken = []
pick = []
for i in range(N):
    for j in range(N):
        if (graph[i][j]==2):
            chicken.append((i,j))
        if (graph[i][j]==1):
            house.append((i,j))
visited = [True]*len(chicken)
#for x,y in chicken:
#    print(x,y)
#print('\n')
#for x,y in house:
#    print(x,y)
def distance(house, chicken):
    house_nx, house_ny = house
    chicken_nx, chicken_ny = chicken
    #print(house_nx, house_ny)
    #print('\n')
    #print(chicken_nx, chicken_ny)
    return abs(house_nx - chicken_nx)+abs(house_ny - chicken_ny)
def DFS(idx):
    global result
    if len(pick)==M:
        tempResult = 0
        for i in range(len(house)):
            dist = INF
            for j in range(len(pick)):
                if visited[j]:
                    dist = min(dist, distance(house[i], pick[j]))
            #가장짧은 치킨거리를 더해야 하므로 안쪽for문을 나와서 tempResult에 dist의 결과를 더해야 한다
            tempResult += dist

        result = min(result, tempResult)
        return
    #아래 두 줄(if문은 없어도 있어도 됨)
    #if idx == len(chicken):
    #    return
    for k in range(idx, len(chicken)):
        if visited[k]:
            pick.append(chicken[k])
            DFS(k+1)
            pick.pop(len(pick)-1)

DFS(0)
print(result)