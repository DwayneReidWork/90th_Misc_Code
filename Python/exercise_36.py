"""
Create a program that reads integers from the user until a blank line is entered. Once all of the integers have been read your program should display all of the negative numbers, followed by all of the zeros, followed by all of the positive numbers. Within each group the numbers should be displayed in the same order that they were entered by the user. For example, if the user enters the values 3, -4, 1, 0, -1, 0, and -2, then your program should output the values -4, -1, -2, 0, 0, 3, and 1. Your program should display each value on its own line.
"""

import random
test = [random.randint(-10,10) for i in range(random.randint(3,15))]
random.shuffle(test)
test.append("")

posNum = list()
negNum = list()
zeroNum = list()

print(f"Your test condition is:\n{test}")
def readNumbers(entries):
    # while True:
    for uInput in entries:
        try:
            # uInput = input("Please enter a value or press enter to end program: ")
            if uInput == "":
                break
            elif int(uInput) > 0:
                posNum.append(int(uInput))
            elif int(uInput) < 0:
                negNum.append(int(uInput))
            else:
                zeroNum.append(int(uInput))
        except:
            pass

    # [print(num) for num in negNum]
    # [print(num) for num in zeroNum]
    # [print(num) for num in posNum]
    orderNumbers = negNum + zeroNum + posNum
    for x in orderNumbers: print(x)
    return None

readNumbers(test)

def myFunct():
    """
    Description

    Parameters:
    -----------
    - None: NoneType

    Returns:
    --------
    - None
    """

    return None
