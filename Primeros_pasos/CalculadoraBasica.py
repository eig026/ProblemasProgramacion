#!/usr/bin/env python3.7
# First Python Program — a Calculator — Shandra Morton
print("Welcome to my first python program — a basic calculator\n")
print("Press 1 for Addition" )
print("Press 2 for Subtraction")
print("Press 3 for Multiplacation")
print("Press 4 for Division \n")
mathop = input("Choose an operation to perform: \n") # Ask for the choice and make sure it is an interger.
if mathop == "1":
    print("You have choosen addition: ")
    first_num = int(input("Input your first number, an integer: "))
    second_num = int(input("Input your second number, an interger: "))
    addition = first_num + second_num
    print(first_num, " + ", second_num, " = ", addition)
elif mathop == "2":
    print("You have choosen subtraction: ")
    first_num = int(input("Input your first number, an integer: "))
    second_num = int(input("Input your second number, an interger: "))
    subtraction = first_num - second_num
    print(first_num, " — ", second_num, " = ", subtraction)
elif mathop == "3":
    print("You have choosen multiplication: ")
    first_num = int(input("Input your first number, an integer: "))
    second_num = int(input("Input your second number, an interger: "))
    multiply = first_num * second_num
    print(first_num, " * ", second_num, " = ", multiply)
elif mathop == "4":
    print("You have choosen division: ")
    first_num = int(input("Input your first number, an integer: "))
    second_num = int(input("Input your second number, an interger: "))
    if second_num != 0:
        divide = first_num / second_num
        print(first_num, " / ", second_num, " = ", divide)
    else:
        print("Choose a number larger than 0 to divide by. Exiting ")
else:
    print("Please enter a valid option. Exiting")
