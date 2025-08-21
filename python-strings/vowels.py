string = input('Enter a string: ')

vowels = ('a', 'e', 'i', 'o', 'u')

n_vowels, n_consonants = 0, 0

for i in string.lower():
    if i in vowels: n_vowels += 1
    elif i.isalpha(): n_consonants += 1

print('No. of vowels: ', n_vowels)
print('No. of consonants: ', n_consonants)