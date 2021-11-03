num = int(input())
word_list = []
for i in range(0, num):
    word_list.append(input())

word_list = set(word_list)
word_list = sorted(word_list)
word_list = sorted(word_list, key=len)

for i in range(0, len(word_list)):
    print(word_list[i])