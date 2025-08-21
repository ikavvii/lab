string = input('Enter a string: ')
length = 0
for i in string: 
    if not i.isspace(): length+=1

print(length)