string = input('Enter a string: ')

count = 0

for i in string: 
    if i.isalpha(): count+=1

print(count)