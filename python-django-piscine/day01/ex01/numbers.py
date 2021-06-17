def numbers():
    with open("numbers.txt", "r") as fd:
        data = fd.read()
        value = data.split(",")
    for i in value:
        i = int(i)
        print(i)

if __name__ == '__main__':
    numbers()
