import sys

def state(argv):
    if len(argv) != 2:
        return
    states = {
            "Oregon"   : "OR",
            "Alabama"  : "AL",
            "New Jersey": "NJ",
            "Colorado" : "CO"
            }
    capital_cities = {
            "OR": "Salem",
            "AL": "Montgomery",
            "NJ": "Trenton",
            "CO": "Denver"
            }
    for key, value in capital_cities.items():
        if value == argv[1]:
            value = key
            break
    else:
        print("Unknown capital city")
        return
    for i, key in states.items():
        if value == key:
            print(i)
            return

if __name__ == '__main__':
    state(sys.argv)
