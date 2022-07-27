nums = [i for i in range(1,1001)]
sentence = "Practice Problems to Drill List Comprehension in Your Head."
six = []

for num in nums:
    if '6' in str(num):
        six.append(num)
        print(num)