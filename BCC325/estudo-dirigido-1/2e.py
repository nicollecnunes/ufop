nums = [i for i in range(1,1001)]
sentence = "Practice Problems to Drill List Comprehension in Your Head."
words = []

list = sentence.split(" ")
for word in list:
    if len(word) < 5:
        words.append(word)
print(words)