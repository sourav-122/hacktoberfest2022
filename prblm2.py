def random(n):
    import string
    import random
    res1 = ''.join(random.choices(string.ascii_uppercase, k =1))
    res2=''.join(random.choices(string.ascii_uppercase+string.ascii_lowercase+string.digits, k = 5))
    res= res1+res2
    print(n+1,"The generated random string : " + str(res))
    return res
    
count=0
for i in range(50):
    k=random(i)
    if k[0]== 'A':
        count+=1
print('Number of generated string starts with A:',count)
