"""
A magic date is a date where the day multiplied by the month is equal to the two digit year. For example, June 10, 1960 is a magic date because June is the sixth month, and 6 times 10 is 60, which is equal to the two digit year. Write a function that determines whether or not a date is a magic date. Use your function to create a main program that finds and displays all of the magic dates in the 20th century.
"""
# for year in range (1900,2000):
#     # month = int(input("Please enter a month: "))
#     # day = int(input("Please enter the day of the month: "))
#     # year = input("Please enter year: ")

def dateCheck(month,day,year):
    yearEnd = int(year%100)
    if month * day == yearEnd:
        magic = "is"
    else:
        magic = "is not"
    return magic

if __name__ == "__main__":
    file = open("magic_dates.txt",'w')
    
    for year in range(1900,2000):
        for month in range(1,13):
            for day in range(1,32):
                check = dateCheck(month,day,year)
                if check == "is":
                    print(f"{day}/{month}/{year} {dateCheck(month,day,year)} a magic date",file=file)

    file.close()