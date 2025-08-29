s = input('s: ')
t = input('t: ')

d = {}
for i, c in enumerate(s):
    if t[i] in d.values() and d[c] == t[i]: continue;
    if c not in d: d[c] = t[i]
    else: 
        print("Not isomorphic") 
        exit(0)
else:print("Isomorphic")