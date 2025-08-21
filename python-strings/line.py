string = input('Enter a string: ')

upper, lower, alpha, digits = 0,0,0,0

for c in string: 
    if c.isupper(): upper += 1
    elif c.islower(): lower += 1
    if c.isalpha(): alpha += 1
    elif c.isdigit(): digits += 1

print(f'''
No of uppercase letters: {upper}
No of lowercase letters: {lower}
No of alphabets: {alpha}
No of digits: {digits}
''')