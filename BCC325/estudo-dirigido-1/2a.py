nums = [i for i in range(1,1001)]
sentence = "Practice Problems to Drill List Comprehension in Your Head."
div = []

for num in nums:
    if num % 8 == 0:
        div.append(num)
        print(num)