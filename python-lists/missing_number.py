n = int(input('n = '))
numbers = [int(i) for i in input('Enter numbers: ').split(' ')]

total_sum = n * (n+1) / 2
for i in numbers:
    total_sum -= i

print(int(total_sum)) # the one missing number