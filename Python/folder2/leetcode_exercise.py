# import random
import random

# establish base list and base dictionary
# myDict = {f"key{i}":(i-random.randint(-5,5)) for i in range(15)}
myList = [i for i in range(15)]
random.shuffle(myList)

target = 5
print(myList)
for index, value in enumerate(myList):
    complement = target - value
    print(index, value, complement)
    if complement in myList:
        # print(f"[{index},{myList.index(complement)}]")
        print([index,myList.index(complement)])
        break