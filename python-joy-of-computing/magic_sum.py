integers = [int(i) for i in input('Input: ').split()]
ans = 0
if len(set(integers)) == len(integers): ans = sum(integers)
print(ans)