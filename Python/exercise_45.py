"""
Two words are anagrams if they contain all of the same letters, but in a different order. For example, "evil" and "live" are anagrams because each contains one e, one i, one l, and one v. Create a program that reads two strings from the user, determines whether or not they are anagrams, and reports the result.
"""

def IsAnagram(string1, string2):
    return sorted(string1) == sorted(string2)

def main():
    str1 = input("Enter your first word: ").lower()
    str2 = input("Enter your second word: ").lower()
    
    # str1 = sorted(str1)
    # str2 = sorted(str2)
    
    # if str1 == str2:
    #     print("They are anagrams.")
    # else:
    #     print("They are not anagrams.")
    
    if IsAnagram(str1,str2):
        print("The words are anagrams.")
    else:
        print("The words are not anagrams.")
    

if __name__ == "__main__":
    main()