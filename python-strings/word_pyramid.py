string = input('Enter a string: ')
length = 0
while  length < len(string):
    length += 1
    print(''.join(string[i] for i in range(length)))