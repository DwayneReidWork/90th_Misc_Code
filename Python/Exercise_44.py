"""
A prime number is an integer greater than 1 that is only divisible by one and itself. Write a function that determines whether or not its parameters is prime, returning True if it is, and False otherwise. Write a main program that reads an integer from the user and displays a message indicating whether or not it is prime. Ensure that the main program will not run if the file containing your solution is imported into another program.
"""

# def Prime(number):
#     if number in (1,2,3,5):
#         prime_number = True
#     elif number % 2 == 0 or number % 3 == 0 or number % 5 == 0 or number % 13 == 0:
#         prime_number = False
#     else:
#         prime_number = True
#     return prime_number
   
# def Prime(number):
#     if number > 1:
#         for i in range(2,(number // 2)+1):
#             if number % i == 0:
#                 return False
#     elif number < 1:
#         return False
#     else:
#         return True
     
def Prime(number):
    if number <= 1:
        return False
    
    for i in range(2,int(number**(1/2))+1):
        if number % i == 0:
            return False
    
    return True

def main():
    uInput = int(input("Please enter a number to see if it is prime or not: "))
    
    is_prime = Prime(uInput)
    if is_prime:
        print("Your number is a prime number.")
    else:
        print("Your number is not a prime number.")

if __name__ == "__main__":
    main()