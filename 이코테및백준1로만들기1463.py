d = [0]*30001
X = int(input())
def Be1():
    #바텀업방식
    for i in range(2, X+1):#d[1]은 숫자1의 연산횟수저장인데, 숫자1은 자기자신이므로 연산이 필요없어 0을 저장하므로 위에서 이미 초기화시에 했으므로 하지 않습니다
        d[i] = d[i-1]+1
        if i%5==0:
            d[i] = min(d[i], d[i//5]+1)
        if i%3==0:
            d[i] = min(d[i], d[i//3]+1)
        if i%2==0:
            d[i] = min(d[i], d[i//2]+1)
    return d[X]

print(Be1())
