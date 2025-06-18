"""
## Exercise 32: Dictionary
Write a function named `reverseLookup` that finds all the keys in a dictionary that map to a specific value. The function will take the dictionary and the value to search for as its only parameters. It will return a (possibly empty) list of keys from the dictionary that map to the provided value.

Include a main program that demonstrates the `reverseLookup` function as part of your solution to this exercise. Your program should create a dictionary and then show that the `reverseLookup` function works correctly when it returns multiple keys, a single key, and no keys. Ensure that your main program only runs when the file containing your solution to this exercise has not been imported into another program.
"""
import random

def generate_tests():
    test_dict = {f"key{value}":(value - random.randint(-5,5)) for value in range(15)}
    # print(test_dict) #
    test_int = random.randint(-15,15)  

    return test_dict,test_int

def print_conditions(test_dict,test_int):
    print(f"""
Test values:
    Dictionary:
        {test_dict}
    Test Integer:
        {test_int}
""")
    return None

# def reverseLookup(myDict:dict, searchVal):
#     a_list = []

#     for key,value in myDict.items():
#         if value == searchVal:
#             a_list.append(key)

#     return a_list

def reverseLookup(dic, val):
    keys_with_var = [key for key, value in dic.items() if value==val]

    print(test_dict)
    
    return keys_with_var

def main(loop=False):
    testDictionary,testValue = generate_tests()
    print_conditions(testDictionary,testValue)
    print(reverseLookup(testDictionary,testValue))

    while loop:
        test_dict, test_int = generate_tests()
        returned_list = reverseLookup(test_dict,test_int)

        if len(returned_list) >= 2:
            print_conditions(test_dict,test_int)
            print(returned_list)
            break

if __name__ == "__main__":
    main(True)