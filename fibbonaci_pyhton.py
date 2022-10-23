
# Fibbonaci in pyhton

x = int(input("Enter the number of elements: "))
a, b = 0, 1
sum = 0
fib = []

for i in range(0, x):
  fib.append(sum)
  a = b
  b = sum
  sum = a+b

print("Result: ", fib)