import sys

def search_cities(city, capital_cities):
    for key, value in capital_cities.items():
        if value == city:
            return key
    else:
        print("Unknown capital city")
        return

def search_states(value, states):
    for i, key in states.items():
        if value == key:
            print(i)
            return

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
    search_states(search_cities(argv[1], capital_cities), states)

if __name__ == '__main__':
    state(sys.argv)
