
counter = {}

for i in range(100):
    for j in range(i, 100):
        product: int = i * i + j * j
        if product not in counter:
            counter[product] = 1
        else:
            counter[product] += 1

for item in counter.keys():
    if counter[item] == 3:
        print(item)

print("end")
