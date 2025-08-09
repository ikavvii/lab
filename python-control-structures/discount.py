purchase_amount = float(input('Enter purchase amount: '))
discount = 0

if purchase_amount >= 5000: 
    discount = 8
elif purchase_amount >= 2000:
    discount = 5

final_bill_amount = purchase_amount * (1 - discount / 100)

print(final_bill_amount)