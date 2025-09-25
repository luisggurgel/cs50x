def main():
    time = input("What time is it? ")
    if convert(time) >= 7 and convert(time) <= 8:
        print("breakfast time")
    elif convert(time) >= 12 and convert(time) <= 13:
        print("lunch time")
    elif convert(time) >= 18 and convert(time) <= 19:
        print("dinner time")

def convert(time):
    hours, minutes = time.split(":")
    minutes = str((int(minutes)/6)*10)
    minutes = minutes.split(".")
    minutes = minutes[0]
    time = [hours, minutes]
    time = ".".join(time)
    return float(time)

if __name__ == "__main__":
    main()
