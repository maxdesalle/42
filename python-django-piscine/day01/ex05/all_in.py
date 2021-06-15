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

    s = argv[1].upper()
    li = stripper(space_remover(list(s.split(","))))

    for x in li:
        print(x)

if __name__ == '__main__':
    state(sys.argv)
