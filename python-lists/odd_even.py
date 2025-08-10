numbers = [int(i) for i in input('Enter numbers: ').split()]
odd_numbers = list(i for i in numbers if i % 2 != 0)
even_numbers = [i for i in numbers if i not in odd_numbers]

print(odd_numbers)
print(even_numbers)
