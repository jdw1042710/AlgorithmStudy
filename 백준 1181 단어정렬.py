N = int(input())
words = list()
for i in range(N):
    temp = input()
    for j in range(len(words)):
        if(len(words[j]) > temp):
            words.insert(j,temp)
            break
        elif(len(words[j]) == temp and words[j] > temp):
            words.insert(j,temp)
            break
        elif(j == (len(words) -1)):
            words.append(temp)

for i in range(N):
    print(words[i])
