prev = int(input('Previous reading: '))
curr = int(input('Current reading: '))
units = curr - prev
bill = 0

if units <= 100: pass
elif units > 500:
    bill = 50 + 100*3.5 + 300*4.6 + (units - 500)*6.6
elif units <= 500:
    if units <= 200:
        bill = 20 + (units - 100)*2
    else:
        bill = 30 + 100*2 + (units - 200)*3

print(bill)
