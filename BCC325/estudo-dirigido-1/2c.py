nums = [i for i in range(1,1001)]
sentence = "Practice Problems to Drill List Comprehension in Your Head."
count = 0

for char in sentence:
    if ' ' in str(char):
        count += 1