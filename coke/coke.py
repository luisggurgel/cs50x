amount_due = 50
verification = [25, 10, 5]
while True:
    if amount_due < 0:
        amount_owed = -amount_due
        print(f"Change Owed: {amount_owed}")
        break
    if amount_due == 0:
        print(f"Change Owed: {amount_due}")
        break
    print(f"Amount Due: {amount_due}")
    temp = int(input("Insert Coin: "))
    for i in range(len(verification)):
        if temp == verification[i]:
            amount_due -= temp


