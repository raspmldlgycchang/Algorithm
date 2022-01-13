#BFS는 그래프에서 가까운노드부터 우선적으로 탐색하는 알고리즘
#큐 사용하고 1. 탐색 시작 노드를 큐에 삽입하고 방문처리
#2. 큐에서 노드를 꺼낸 뒤에 해당 노드의 인접 노드 중에서 방문하징 않은 노드를 모두 큐에 삽입하고
#방문처리
#3. 더이상 2번의 과정을 수행할 수 없을 때까지 반복
from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])
    #queue자료형을 이용하면 가장 먼저 들어왔던 원소를 가장 먼저 꺼낼 수 있으므로
    visited[start] = True
    while queue:#while(!q.empty()) 이건 자바에서
        v = queue.popleft()
        #queue에서 가장 처음에 들어간것부터 빼낸다
        print(v, end=' ')
        for i in graph[v]:#지금빼내는 원소에
            if not visited[i]:#만약 방문안한 노드가 있다면
                #큐에 그 노드들을 전부 다 넣어버릴 껀데 그걸 for문으로 하니까
                #한 번 for문 루프에서 한 개의 노드를 넣는다(graph[i])
                queue.append(i)
                visited[i] = True
    #모든 구현탐색이 끝난뒤 FIFO방식으로 모든 원소를 큐에서 빼낸다
    #그러면 탐색이 완료된다
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]
visited = [False]*9
bfs(graph, 1, visited)