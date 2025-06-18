"""
Python uses the # character to mark the beginning of a comment. The comment ends at the end of the line containing the # character. In this exercise, you will create a program that removes all of the comments from a Python source file. Check each line in the file to determine if a # character is present. If it is, then your program should remove all of the characters from the # character to the end of the line (we'll ignore the situation where the comment character occurs inside of a string). Save the modified file using a new name that will be entered by the user. The user will also enter the name of the input file. Ensure that an appropriate error message is displayed if a problem is encountered while accessing the files.
"""

# removeMe = '#'
# filename = 'saved_output' # input("Select a new name for the file: ")
# filePath = f"/home/mnelson/projects/test_git_repo/{filename}.py"

# def writeToNew():
#     """
    
#     """
#     with open("/home/mnelson/projects/test_git_repo/exercise_37.py",'r') as firstFile, open(filePath,"a") as secondFile:
#         for line in firstFile:
#             secondFile.write(line)

# def deleteComments():
#     with open(filePath,'r') as file:
#         lines = file.readlines()

#     with open(filePath,'w') as f:
#         for line in lines:
#             if removeMe not in line:
#                 f.write(line)

# writeToNew()

# deleteComments()

def processFile(inputFile,outputFile):
    with open(inputFile,'r') as inFile, open(outputFile,'w') as outFile:
        for line in inFile.readlines():
            if '#' in line:
                line = line.split('#')[0] + "\n"
            else:
                pass
                # print("# not found")
            outFile.write(line)


def main():
    inputFile = "exercise_37.py"
    outputFile = "saved_output.py"

    processFile(inputFile,outputFile)

if __name__ == "__main__":
    main()

