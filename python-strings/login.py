username = input('Enter the username: ')
password = input('Enter the password: ')

if username.isalpha() and len(password) == 7 and password[0].isupper():
    print('The user login created successfully') 
else: print('Password length must be strictly 7 and it should start with uppercase letter.')
