character = input('Character to print: ')
pattern = input('Format to print: ')
pattern = [int(pattern[i]) for i in range(len(pattern))]
for i in pattern: print(character * i)