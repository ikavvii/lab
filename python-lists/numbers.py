numbers_list = input('Enter list of numbers: ').split(' ')

total_sum = 0
for i in numbers_list:
    total_sum += int(i) 

average = total_sum / len(numbers_list)

print('Sum: ', total_sum)
print('Average: ', average)
