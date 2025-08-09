weight = float(input('Enter weight (in kg): '))
height = float(input('Enter height (in meters)'))

bmi = weight / height ** 2

if bmi < 18.5 :
    print('Underweight')
elif bmi >= 30.0:
    print('Obese')
elif bmi >= 25.0:
    print('Overweight')
else: 
    print('Healthy')

bmi = weight / height ** 2


