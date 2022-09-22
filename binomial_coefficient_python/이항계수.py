def bino_coef(n,k):
    if n<k:
        return 0
    cache = [[-1 for _ in range(n+1)] for _ in range(n+1)]
    def choose(times, got):
        if times == n:
            return got == k
        if cache[times][got] != -1:
            return cache[times][got]
        cache[times][got] = choose(times+1, got) + choose(times+1, got+1)
        return cache[times][got]

    return choose(0,0)

if __name__ == "__main__":
    print("이항계수.py가 직접 호출됨: ", __name__)
else:
    print("이항계수.py가 import되어 호출됨: ", __name__)

print(bino_coef(6,4))