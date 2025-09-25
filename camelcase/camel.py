camelCase = input("camelCase: ")
snake_case = []
for i in range(len(camelCase)):
    snake_case.append(camelCase[i])
for i in range(len(snake_case)):
    if snake_case[i].isupper():
        snake_case[i] = snake_case[i].lower()
        snake_case.insert(i, "_")
snake_case = "".join(snake_case)
print(snake_case)
