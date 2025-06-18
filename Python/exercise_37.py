"""
In this exercise, you will simulate 1000 rolls of two dice. Begin by writing a function that simulates rolling a pair of six-sided dice. Your function will not take any parameters. It will return the total that was rolled on two dice as its only result.

Write a main program that uses your function to simulate rolling two six-sided dice 1000 times. As your program runs, it should count the number of times that each total occurs. Then it should display a table that summarizes this data. Express the frequency for each total as a percentage of the total number of rolls. Your program should also display the percentage expected by probability theory for each total. Sample output is shown below.
"""

import random
from collections import Counter

table = {
    'total':[list(range(2,13))],
    'simulated':[],
    'expected':[2.78,5.56,8.33,11.11,13.89,16.67,13.89,11.11,8.33,5.56,2.78]
}

trials = 1000 # Let's define my trial size

def diceRoll():
    return random.randint(1,6) + random.randint(1,6)

def updateTable():
    tableCounter = []
    for x in range(trials): # if I put a comment here, this should get removed
        diceSum = diceRoll()
        tableCounter.append(diceSum)

    tally = Counter(tableCounter)
    
    counter = 3
    tableHeaders = [" Total "," Simulated Percent ", " Expected Percent "]
    print(tableHeaders[0],tableHeaders[1],tableHeaders[2],sep="\t")
    for sumValue,count in sorted(tally.items()):
        #  Let's get the expected probability!
        if sumValue < 8:
            expected_prob = ((sumValue - 1) / 36) * 100
        elif sumValue > 7: # sample removal
            expected_prob = ((sumValue - counter)/36) * 100
            counter += 2
        # print(f'{sumValue:}, {(count / trials)*100:.2f}, {expected_prob:.2f}')
        print(sumValue,f"{((count / trials)*100):.2f}",f"{expected_prob:.2f}",sep='\t\t\t')

def main():
    updateTable()

if __name__ == "__main__":
    main()