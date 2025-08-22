phrase = input('Enter a phrase: ').lower()

text = ''.join(c for c in phrase if c.isalnum())

print(text == text[::-1])

