h = int(input())

count = 0
for i in range(h+1):#h까지 해야하기 때문에
    for j in range(60):#60은 하지 않고 59까지 하기 때문에
        for k in range(60):#같은 이유로 59까지라서
            if '3' in str(i)+str(j)+str(k):
                count += 1;
print(count)