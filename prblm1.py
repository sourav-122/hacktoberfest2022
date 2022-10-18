a=101
b=125
import random
def Rand(start, end, num):
	res = []
	for j in range(num):
		res.append(random.randint(start, end))
	return res
num = 100
start = 101
end = 200
li=Rand(start, end, num)
print('Random numbers are:',li)

for m in range(4):
    count=0
    for k in li:
        if k<=b and k>=a:
            count+=1
    print(a,'-',b,':',count)
    a+=25
    b+=25

    
