vogais = ["A", "E", "I", "O", "U"]

phrase = input("Input: ")
new_phrase = []

for char in phrase:
    new_phrase.append(char)
for i in reversed(range(len(new_phrase))):
    if new_phrase[i].upper() in vogais:
        new_phrase.pop(i)
result = "".join(new_phrase)
print(result)
