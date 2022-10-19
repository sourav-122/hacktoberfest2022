n=int(input())
li=[tuple(int(j) for j in input().split())for i in range(n)]
print('list of tuples:',li)
for j in range(n-1):
    if li[j][1]>li[j+1][1]:
        li[j],li[j+1]=li[j+1],li[j]
print('list of tuples:',li)
