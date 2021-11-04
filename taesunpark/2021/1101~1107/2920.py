scale_list = [1, 2, 3, 4, 5, 6, 7, 8]

input_list = list(map(int, input().split()))

if input_list == scale_list:
    print("ascending")
elif input_list == list(reversed(scale_list)):
    print("descending")
else:
    print("mixed")

