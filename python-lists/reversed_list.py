numbers = [int(i) for i in input('Enter numbers: ').split(' ')]

i = len(numbers)
reversed_numbers_list = []

while i > 0:
    i-=1
    reversed_numbers_list.append(numbers[i])

print(reversed_numbers_list)