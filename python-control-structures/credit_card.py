age = int(input('Enter your age: '))

print('Card holder type:')
print('1- Primary applicant')
print('2- Add-on card applicant')
card_type = int(input('Select: '))

if card_type == 1 and age >=21 and age <= 60:
    print('Income type: ')    
    print('''
          1- Salaried
          2- Self-employed
          3- Student
          4- Retired pensioner
          5- Unemployed''')
    income_type = int(input('Select: '))
    if income_type in range(1, 5) \
        and float(input('Enter income (gross): ')) >= 300000:
        print('You are eligible to apply for primary card.')
    else: 
        print('You are not eligible.')
elif card_type == 2 and age > 18:
    print('You are eligible to apply for add-on card.')
else:
    print('You are not eligible.')