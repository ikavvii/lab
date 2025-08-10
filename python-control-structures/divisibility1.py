# check how many numbers between a and b are divisible by c.

a = int(input('a: '))
b = int(input('b: '))
c = int(input('c: '))
ans = 0

for i in range(a, b + 1):
    if i % c == 0: ans+= 1

print(ans)