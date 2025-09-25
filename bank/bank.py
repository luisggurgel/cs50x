greeting = input("Greeting: ")
greeting = greeting.split()

if greeting[0][0].lower() == "h":
    if greeting[0][1].lower() == "e" and greeting[0][2].lower() == "l" and greeting[0][3].lower() == "l" and greeting[0][4].lower() == "o":
        print("$0")
    else:
        print("$20")
else:
    print("$100")
