name = input('Enter the shape: ')
if name == 'S':
    length = int(input('Enter side length: '))
    print('Area: ', length ** 2)
elif name == 'C':
    radius = int(input('Enter radius: ' ))
    print('Area: ', 3.14 * radius ** 2)
