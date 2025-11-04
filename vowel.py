word=input("enter the word")
lst='aeiouAEIOU'
vowel=[]
for char in word:
    if char in lst:
        vowel.append(char)
print(vowel)
        
