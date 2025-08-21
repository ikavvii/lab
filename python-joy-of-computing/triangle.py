sides = [int(i) for i in input('Enter: ').split(' ')]
sorted_sides = sides.sort()

if min(sorted_sides) == max(sorted_sides):
    print('Equilateral')
elif set(len(sides)) == len(sides):
    print('Isosceles')
else:
    print('Scalene')