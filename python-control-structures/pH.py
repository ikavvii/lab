pH = int(input('pH: '))
if pH > 7:
    if pH<12:
        print('Alkaline')
    else:
        print('Very Alkaline')
elif pH==7:
    print('Neutral')
elif pH>2:
    print('Acidic')
else:
    print('Very Acidic')

print('pH levels checked!')                                                                                                                                              