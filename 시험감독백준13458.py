N = int(input())
A = []
A= list(map(int, input().split()))
B,C = map(int, input().split())

result = 0
for i in range(N):
    A[i] = A[i]-B
    result+= 1
    if A[i]>0:
        result += A[i]//C
    #위에서 A[i]를 변경하는 것이 아니라서
    #A[i]!=0을 바로 위의 부감독관 추가 조건으로 쓰고 난 뒤의 추가연산으로 쓰려면
    #A[i]가 C보다 작은 수로 나머지가 남은 경우는 안쪽 if문으로 처리
        if A[i]%C != 0:
            result+=1
print(result)
