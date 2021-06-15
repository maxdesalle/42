import sys

def capital_city(argv):
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
    for key, value in states.items():
        if key == argv[1]:
            key = value
            break
    else:
        print("Unknown state")
        return
    for i, value in capital_cities.items():
        if i == key:
            print(value)
            return

if __name__ == '__main__':
    capital_city(sys.argv)
