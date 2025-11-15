# using print(*object, sep=' ', end='\n')
name= input("What's your name? ")
print(*name, sep='_', end=' kumar')

# To remove whitespace from str, to capitalize and to split username into first and last name
name= input("what's your name? ").strip().title()
first, last = name.split(" ")
print(f"Hello,{first}")
