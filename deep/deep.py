solution = ["42", "forty two", "forty-two"]

question = input("What is the Answer to the Great Question of Life, the Universe, and Everything?")

if question.lower().strip() in solution:
    print("Yes")
else:
    print("No")
