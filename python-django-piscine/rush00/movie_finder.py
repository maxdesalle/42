import requests, json, random


def movie_finder():

    movies = {}
    search = []
    database = ["titanic", "inception", "goodfellas", "se7en", "intersteller", "gladiator", "whiplash", "casablanca", "alien", "joker", "hamilton", "coco", "capernaum", "braveheart", "idiots", "amadeus", "vertigo", "ikiru", "dangal", "1917", "incendies", "snatch", "scarface", "up", "heat", "rashomon", "yojimbo", "ran", "unforgiven", "casino", "chinatown", "klaus", "fargo", "warrior", "room", "prisoners", "andhadhun", "network", "logan", "platoon", "rush", "rebecca"]
    search = random.sample(database, 10)

    for i in search:

        r = requests.get("https://www.omdbapi.com/?t={}&apikey=af1c662c".format(i))
        r = json.loads(r.text)

        for key, value in r.items():
            if "imdbRating" in key:
                movies.update({i: value})
                break

    print(movies)


if __name__ == '__main__':
    movie_finder()
