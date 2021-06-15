import sys

def search_states(state):
    
    states = {
            "Oregon"   : "OR",
            "Alabama"  : "AL",
            "New Jersey": "NJ",
            "Colorado" : "CO"
            }

    for key, value in states.items():
        if key == state:
            return value
    else:
        print("Unknown state")
        return

def search_cities(value):
    
    capital_cities = {
            "OR": "Salem",
            "AL": "Montgomery",
            "NJ": "Trenton",
            "CO": "Denver"
            }

    for i, key in capital_cities.items():
        if value == i:
            print(key)
            return

def state(argv):

    if len(argv) != 2:
        return
    
    search_cities(search_states(argv[1]))

if __name__ == '__main__':
    state(sys.argv)
