nums = [i for i in range(1,1001)]
sentence = "Practice Problems to Drill List Comprehension in Your Head."

for vogal in "AEIOUaeiou":
    sentence = sentence.replace(vogal, '')
print(sentence)