from django.db import models
import random, requests, json

class gameGestion(models.Model):

    _pickle = {}

    playerMovieDex = []

    def __init__(self, pickle=None):
        if pickle is None:
            pass
        else:
            self._pickle = pickle
        self.playerStrength = 1
        self.movieBalls = 5


    database = ["titanic", "inception",
    "goodfellas", "se7en", "interstellar",
    "gladiator", "radhe", "gigli", "smolensk",
    "glitter", "cats", "steel", "rollerball", "bloodrayne",
    "bratz", "catwoman", "feardotcom", "ikiru", "dangal",
    "1917", "incendies", "snatch", "scarface", "up", "heat",
    "rashomon", "yojimbo", "ran", "unforgiven", "casino", "chinatown",
    "klaus", "fargo", "warrior", "room", "prisoners", "andhadhun", "network",
    "logan", "platoon", "rush", "rebecca"]

    def startNewBattle(self, name):
        pass

    def load(self, pickle):
        _pickle = pickle
        pass

    def dump(self):
        pass

    def get_random_movie(self):
        randomMovie = random.choice(self.database)
        self.playerMovieDex.append(randomMovie)

        # __Debbug__
        print("Film au hasard = ", randomMovie)
        print("MovieDex du joueur = ", self.playerMovieDex)
        # Retourne le film choisi au hasard
        return randomMovie


    def load_default_settings(self):
        pass

    def get_strength(self):
        return self.playerStrength

    def captureRating(self, rating):
        valueOfMovie = float(rating)
        C = float(50 - (valueOfMovie * 10) + (self.playerStrength * 5))
        
        if C in range (1, 90):
            pass
        elif C <= 1:
            C = 1
        elif C >= 90:
            C = 90
        return str(C)


    def get_movie(self, name):
        if name not in self.database:
            return {None : 1}
        requestOmdb = requests.get("https://www.omdbapi.com/?t={}&apikey=af1c662c".format(name))
        requestOmdb = json.loads(requestOmdb.text)
        displayableDict = {
            "CaptureRate" : self.captureRating(requestOmdb['imdbRating']),
            "imdbRating" : requestOmdb['imdbRating'],
            "Poster" : requestOmdb['Poster'],
            "Title" : requestOmdb['Title'],
            "numberOfMovieballs" : self.movieBalls,
            "playerStrength" : self.playerStrength
        }
        return displayableDict

    def findMovieball(self):
        self.movieBalls += 1
# Create your models here.
