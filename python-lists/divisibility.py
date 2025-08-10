numbers_list = [int(i) for i in input('Enter list of numbers: ').split(' ')]

number = int(input('Enter a number: (to check divisibility) '))

filtered_list = [i for i in numbers_list if i % number == 0]
print(filtered_list)
