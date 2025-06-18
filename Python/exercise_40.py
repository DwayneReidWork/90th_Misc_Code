"""
The novel "Gadsby" is over 50,000 words in length. While 50,000 words isn't normally remarkable for a novel, it is in this case because none of the words in the book use the letter "e". This is particularly noteworthy when one considers that "e" is the most common letter in English.

Write a program that reads a list of words from a file and determines what proportion of the words use each letter of the alphabet. Display the result for all 26 letters. Include an additional message identifying the letter that is used in the smallest proportion of the words. Your program should ignore any punctuation marks and it should treat uppercase and lowercase letters as equivalent.

Use the following website to generate a sample text: https://loremipsum.io/

Store this in a text file and read it into your program.

Use the following website to check your results! https://www.browserling.com/tools/letter-frequency
"""

def letterFrequency(fileName, letter):
    myFile = open(fileName,'r')
    text = myFile.read().upper()
    counter = 0

    for character in text:
        if character == chr(letter):
            counter += 1

    return counter

f = open("letter_frequency.txt",'w')
myLetters = dict()
for i in range(ord("A"),ord("Z")+1):
    myLetters[chr(i)] = letterFrequency("lorem_ipsum.txt",i)
# print(min(myLetters))
# print(myLetters)
for key in myLetters.keys():
    # print(key)
    # value = str(myLetters[key])
    f.write(key + ":" + str(myLetters[key])+'\n')
f.close()