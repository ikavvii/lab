mathematics = int(input('Mathematics: '))
physics = int(input('Physics: '))
chemistry = int(input('Chemistry: '))

total = mathematics + physics + chemistry

if mathematics>=60 and physics>=50 and (chemistry>=40 or mathematics + physics >= 150):
    print('Eligible')
else:
    print('Not eligible')
