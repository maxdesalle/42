import sys

def space_remover(li):

    for i in li:
        if i.isspace():
            li.remove(i)

    return li


def stripper(li):

    counter = 0

    for i in li:
        i = i.strip()
        li[counter] = i
        counter += 1

    return li


def search_cities(city, option, state):

    capital_cities = {
            "OR": "Salem",
            "AL": "Montgomery",
            "NJ": "Trenton",
            "CO": "Denver"
            }

    if option == 1:
        for key, value in capital_cities.items():
            if value.upper() == city.upper():
                return key
        else:
            return 0
    elif option == 2:
        for key, value in capital_cities.items():
            if key.upper() == city.upper():
                print(value.title(), "is the capital of", state.title())
                return


def search_states(state, option, city):
    
    states = {
            "Oregon"   : "OR",
            "Alabama"  : "AL",
            "New Jersey": "NJ",
            "Colorado" : "CO"
            }

    if option == 1:
        for key, value in states.items():
            if key.upper() == state.upper():
                return value
        else:
            return 0
    elif option == 2:
        for key, value in states.items():
            if value.upper() == state.upper():
                print(city.title(), "is the capital of", key.title())
                return


def city_state(li):

    for i in li:
        if search_cities(i, 1, i) != 0:
            state = search_cities(i, 1, i)
            search_states(state, 2, i)
        elif search_states(i, 1, i) != 0:
            city = search_states(i, 1, i)
            search_cities(city, 2, i)
        else:
            print(i, "is neither a capital city nor a state")


def all_in(argv):

    if len(argv) != 2:
        return

    s = argv[1]
    li = stripper(space_remover(list(s.split(","))))

    city_state(li)


if __name__ == '__main__':
    all_in(sys.argv)
