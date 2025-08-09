lsd = 5
n = int(input('Enter range: '))

# displays the square of those numbers only the given least significant digit
for i in range(lsd, n+1, 10):
    print(i*i, end=', ')
print("\b\b ")
