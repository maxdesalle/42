import requests, json, random


def randnum_gen(i, moviemons):

    position = random.randint(1, 101)

    for key, value in moviemons.items():
        if position == value:
            return randnum_gen(i, moviemons)

    moviemons.update({i: position})

    return moviemons


def moviemon_finder():

    moviemons = {}
    search = []
    database = ["titanic", "inception", "goodfellas", "se7en", "interstellar", "gladiator", "radhe", "gigli", "smolensk", "glitter", "cats", "steel", "rollerball", "bloodrayne", "bratz", "catwoman", "feardotcom", "ikiru", "dangal", "1917", "incendies", "snatch", "scarface", "up", "heat", "rashomon", "yojimbo", "ran", "unforgiven", "casino", "chinatown", "klaus", "fargo", "warrior", "room", "prisoners", "andhadhun", "network", "logan", "platoon", "rush", "rebecca"]
    search = random.sample(database, 10)

    for i in search:

        moviemons = randnum_gen(i, moviemons)

    return moviemons


def movieball_finder():
    
    movieballs = {}
    
    for i in range(1, 11):
        
        value = random.randint(1, 101)
        movieballs[i] = value

    return movieballs
