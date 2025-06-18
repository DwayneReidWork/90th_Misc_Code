"""
Write a script to search for a specific word in a file and provides options to count occurrences or return line numbers where the word appears. With no optional arguments, print each line where the term appears.
"""
import argparse

# Create my parser object
parser = argparse.ArgumentParser(description="hi")

# Create our arguments
parser.add_argument("filename",help="File you would like to search through",type=str)
parser.add_argument("word",type=str,help="Word you would like to find.")
parser.add_argument("--count",action="store_true",help="Return the number of occurrences of the word in the file.")
parser.add_argument("--line_nums",action="store_true",help="Returns the line numbers the word is found on.")

# Parse our arguments for calling and usage
args = parser.parse_args()

# 
try:
    with open(args.filename,'r') as f:
        content = f.readlines()
        if args.line_nums == True:
            for line_number, line in enumerate(content,start=1):
                if args.word in line:
                    print(f'line {line_number}:',line.strip())
        elif args.count == True:
            counter = 0
            for line in content:
                if args.word in line:
                    counter += 1
            print(f"Your word appears {counter} times.")
        else:
            for line in content:
                if args.word in line:
                    print(line.strip())
except:
    print("File not found.")