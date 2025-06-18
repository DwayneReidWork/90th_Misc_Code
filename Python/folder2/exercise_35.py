"""
Write a function that determines how many days there are in a particular month. Your function will take two parameters: the month as an integer between 1 and 12, and the year as a four digit integer. Ensure that your function reports the correct number of days in February for leap years. Include a main program that reads a month and year from the user and displays the number of days in that month. Modify your program from exercise 33 to be used here within the main program.
"""

from exercise_33 import leapYear

def daysInYear(month:int, year:int):
    """
    
    """

    if month == 2:
        if ((year % 4 == 0) or (year % 400 == 0)) and (year % 100 != 0):
            days = 29
        else:
            days = 28
    elif month in (1,3,5,7,8,10,12):
        days = 31
    elif month in (4,6,9,11):
        days = 30
    else:
        return "This is not a valid date"

    return days

def main():
    """
    
    """

    while True:
        try:
            month, year = int(input("Please enter a valid month: ")),int(input("Please enter a valid year: "))
            # month,year = [int(i) for i in input("Please enter a month and year, separated by a comma").split(',')]
            print(month,year)
            # print("Month and year passed")
            break
        except:
            print('What you entered was not a number. Please enter a number.')
        
    result = daysInYear(month,year)
    # if type(result) == type(str()):
    #     print(result)
    print(result)

    print("Program exiting. Goodbye.")

if __name__ == "__main__":
    main()