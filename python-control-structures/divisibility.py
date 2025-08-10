n = int(input('Enter a number: '))

for i in range(700, 901):
    if i % n == 0:
        print(i, end=',')

print('\b ')