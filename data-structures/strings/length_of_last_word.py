s = input('Enter s: ')
last_word = ''
index = 0
for i, c in enumerate(s):
    if c == ' ':
        index =i

last_word = s[index+1:]
print(last_word)
print(len(last_word))