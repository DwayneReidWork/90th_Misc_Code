"""
Write a script that generates a random password with optional flags for including special characters, numbers, and adjusting the length.
"""
import argparse
import random

parser = argparse.ArgumentParser(description="Password generator")

parser.add_argument("length",type=int,help="Desired length of password.")
parser.add_argument("--spec_char",type=str,help="Add special characters (Y/N)?")
parser.add_argument("--num",type=str,help="Add numbers to password (Y/N)?")

args = parser.parse_args()
password = str()

for i in range(args.length):
    if args.spec_char == 'Y' and args.num == 'Y':
        randchars = random.choice(['num','spec','char'])
    elif args.spec_char == 'N' and args.num == 'Y':
        randchars = random.choice(['num','char'])
    elif args.spec_char == 'Y' and args.num == 'N':
        randchars = random.choice(['spec','char'])
    else:
        randchars = 'char'
    
    if randchars == 'num':
        temp = random.choice([1,2,3,4,5,6,7,8,9,0])
        temp = str(temp)
        password = password + temp
    elif randchars == 'spec':
        temp = random.choice("!@#$%^&*")
        password = password + temp
    elif randchars == 'char':
        upper_lower = random.choice(['up','low'])
        if upper_lower == 'up':
            temp = random.choice('QWERTYUIOPASDFGHJKLZXCVBNM')
            password = password + temp
        elif upper_lower == 'low':
            temp = random.choice ('QWERTYUIOPASDFGHJKLZXCVBNM'.lower())
            password = password + temp

print(password)
