string = input('Enter a string: ')

new = ''
for i, c in enumerate(string):
    if i % 2 == 0: new += c

print(new)
