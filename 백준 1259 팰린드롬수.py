def isPalindrome(string):
    i, j = 0, len(string) - 1
    while(i<j):
        if(string[i] != string[j]):
            return False
        i += 1
        j -= 1
    return True


    
string = input()
while (string != '0'):
    if(isPalindrome(string)):
        print("yes")
    else:
        print("no")
    string = input()
