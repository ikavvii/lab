string = input('Enter a stirng: ')

digits = [int(i) for i in string if i.isdigit()]

print(digits)
print(sum(digits))
