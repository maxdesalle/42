def numbers():
    for line in open("numbers.txt", "r"):
        value = line.split(",")
    for i in value:
        i = int(i)
        print(i)

if __name__ == '__main__':
    numbers()
