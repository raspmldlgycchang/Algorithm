N,M = map(int, input().split())
INF = 987654321
result = INF
graph = []
for i in range(N):
    graph.append(list(map(int, input().split())))
house = []
chicken = []
pick = []
visited = [[True]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if (graph[i][j]==2):
            chicken.append((i,j))
        if (graph[i][j]==1):
            house.append((i,j))

for x,y in chicken:
    print(x,y)
print('\n')
for x,y in house:
    print(x,y)
def distance(house, chicken):
    house_nx, house_ny = house
    chicken_nx, chicken_ny = chicken
    #print(house_nx, house_ny)
    #print('\n')
    #print(chicken_nx, chicken_ny)
    return abs(house_nx - chicken_nx)+abs(house_ny - chicken_ny)
def DFS(idx, selected):
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
    if idx==len(chicken):
        return
    for k in range(idx, len(chicken)):
        pick.append(chicken[k])

        DFS(k+1, selected+1)
        pick.remove(chicken[k])
        selected -=1
        DFS(k+1, selected)
    #if idx == len(chicken):
    #    return
    #visited[idx] = True
    #다음 인덱스를 방문했다고 표시해주고 호출이 끝나면 그 인덱스 방문을 없애서 selected에서 그 지점을 없애고
    #DFS에서 방금 없앤 인덱스에서 1을 더한 인덱스를 호출해서 다음 3개를 pick이라는 배열에 만들고

    #하나의 pos라는 인덱스에 대해서 DFS가 끝났다면 pick이라는 배열에서 거꾸로 DFS를 반환하고
    #DFS(idx + 1, selected + 1)
    #visited[idx] = False
    #지금 인덱스는 selected에 안 넣고 다음 인덱스를 selected로 넣기 위해서
    #현재 인덱스는 방문안한걸로 바꿔놓고 다음 인덱스를 selected가 1증가되도록 해서
    #selected==M:조건 만족하게 해서 수행해야하는 문장 수행하게 한다
    #DFS(idx + 1, selected)

DFS(0, 0)#selected 0을 넘겨줌
print(result)