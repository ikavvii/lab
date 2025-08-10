print('Rooms available:')
rooms = {2: 5000, 3: 6000, 4: 7000}

for people in rooms.keys():
    cost = rooms[people]
    print(f"{people} people: Rs.{cost}")

room_type = int(input('Select: '))
n = int(input('Additional people? (Max 2 are allowed), Rs.500/person : ')) or 0
if n > 2: print('Room not available'); exit()
if n < 0: print('Invalid input'); exit()

room_cost = rooms[room_type] + n * 500

purpose = input('Purpose of stay: ')
age = int(input('Enter your age: '))

discount = 0
if 'business' in purpose: discount = 20
elif age > 60: discount = 15

room_cost = room_cost * (1 - discount / 100)

print(room_cost)
