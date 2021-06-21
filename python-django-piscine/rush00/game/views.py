from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.forms import ChoiceField
from django import forms
from game.models import gameGestion
from shutil import copyfile
import random
import pickle

def titlescreen(request):

    return render(request, "titlescreen.html")


def worldmap(request):

    with open('filename.pickle', 'rb') as handle:
        position = pickle.load(handle)

    history = position
    position = position['a']
    a = 0

    for key, value in position.items():
        if (a < key):
            a = key

    database = {'position': position[key]}

    dbworld = {'position': position[a], 'movieballs': history['e']['movieballs'], 'moviemonid': history['f']['moviemonid'], 'movieballcatch': history['g']['movieballcatch'], 'moviemoncatch': history['h']['moviemoncatch']}

    return render(request, "worldmap.html", dbworld)


def right_move(request):

    with open('filename.pickle', 'rb') as handle:
        position = pickle.load(handle)

    history = position
    history['g']['movieballcatch'] = False
    history['h']['moviemoncatch'] = False
    a = 0

    for key, value in history['a'].items():
        if (a < key):
            a = key
            location = value

    if history['a'][a] % 10 == 0:
        pass
    else:
        a += 1
        location += 1
        history['a'].update({a: location})
    
    x = 0

    for key, value in history['c'].items():
        if (history['a'][a] == value):
            history['e']['movieballs'] += 1
            history['g']['movieballcatch'] = True
            x = 1
            break

    if (x == 1):
        del history['c'][key]
    
    for key, value in history['b'].items():
        if (history['a'][a] == value):
            history['f']['moviemonid'] = key
            history['h']['moviemoncatch'] = True
            break

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/worldmap')


def left_move(request):

    with open('filename.pickle', 'rb') as handle:
        position = pickle.load(handle)

    history = position
    history['g']['movieballcatch'] = False
    history['h']['moviemoncatch'] = False
    a = 0

    for key, value in history['a'].items():
        if (a < key):
            a = key
            location = value

    if history['a'][a] % 10 == 1:
        pass
    else:
        a += 1
        location -= 1
        history['a'].update({a: location})

    x = 0

    for key, value in history['c'].items():
        if (history['a'][a] == value):
            history['e']['movieballs'] += 1
            history['g']['movieballcatch'] = True
            x = 1
            break

    if (x == 1):
        del history['c'][key]

    for key, value in history['b'].items():
        if (history['a'][a] == value):
            history['f']['moviemonid'] = key
            history['h']['moviemoncatch'] = True
            break

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(position, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/worldmap')


def up_move(request):

    with open('filename.pickle', 'rb') as handle:
        position = pickle.load(handle)

    history = position
    history['g']['movieballcatch'] = False
    history['h']['moviemoncatch'] = False
    a = 0

    for key, value in history['a'].items():
        if (a < key):
            a = key
            location = value

    if history['a'][a] in range(1,11):
        pass
    else:
        a += 1
        location -= 10
        history['a'].update({a: location})

    x = 0

    for key, value in history['c'].items():
        if (history['a'][a] == value):
            history['e']['movieballs'] += 1
            history['g']['movieballcatch'] = True
            x = 1
            break

    if (x == 1):
        del history['c'][key]

    for key, value in history['b'].items():
        if (history['a'][a] == value):
            history['f']['moviemonid'] = key
            history['h']['moviemoncatch'] = True
            break

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(position, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/worldmap')


def down_move(request):

    with open('filename.pickle', 'rb') as handle:
        position = pickle.load(handle)

    history = position
    history['g']['movieballcatch'] = False
    history['h']['moviemoncatch'] = False
    a = 0

    for key, value in history['a'].items():
        if (a < key):
            a = key
            location = value

    if history['a'][a] in range(91,101):
        pass
    else:
        a += 1
        location += 10
        history['a'].update({a: location})

    x = 0

    for key, value in history['c'].items():
        if (history['a'][a] == value):
            history['e']['movieballs'] += 1
            history['g']['movieballcatch'] = True
            x = 1
            break

    if (x == 1):
        del history['c'][key]

    for key, value in history['b'].items():
        if (history['a'][a] == value):
            history['f']['moviemonid'] = key
            history['h']['moviemoncatch'] = True
            break

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(position, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/worldmap')


def title_redirect(request):
    return redirect('http://127.0.0.1:8000/')


def world_redirect(request):
    return redirect('http://127.0.0.1:8000/worldmap')


def battle_render(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    movie = gameGestion()
    value = history['f']['moviemonid']
    movie_dict = movie.get_movie(value)
    history['f']['imdbrating'] = movie_dict['imdbRating']

    dbworld = {'movieballs': history['e']['movieballs'], 'moviemonid': history['f']['moviemonid'], 'movieballcatch': history['g']['movieballcatch'], 'moviemoncatch': history['h']['moviemoncatch'], 'capturerate': movie_dict['CaptureRate'], 'imdbrating': movie_dict['imdbRating'], 'poster': movie_dict['Poster'], 'titlemon': movie_dict['Title'], 'moviemoncaught': history['i']['moviemoncaught']}

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return render(request, "getmovie.html", dbworld)


def battle(request):
    # return render(request, "battle.html", {})
    return HttpResponse("<h1>It works!</h1>")


def battle_attack(request):

    with open('filename.pickle', 'rb') as handle:
        db = pickle.load(handle)

    db['e']['movieballs'] -= 1
    
    valueOfMovie = float(db['f']['imdbrating'])
    C = float(50 - (valueOfMovie * 10) + (db['d']['player_strength'] * 5))
    
    if C in range (1, 90):
        pass
    elif C <= 1:
        C = 1
    elif C >= 90:
        C = 90

    a = random.randint(1, 100)

    counter = 0

    if (a in range(0, int(C) + 1)):
        db['i']['moviemoncaught'] = True
        db['j'].append(db['f']['moviemonid'])
    else:
        db['i']['moviemoncaught'] = False

    history = db

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/battle/{}'.format(db['f']['moviemonid']))


def worldmap_return(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    movieid = history['f']['moviemonid']
    history['f']['moviemonid'] = None
    history['f']['imdbrating'] = None
    history['h']['moviemoncatch'] = False
    history['i']['moviemoncaught'] = False
    del history['b'][movieid]

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/worldmap')


def moviedex(request):
    # return render(request, "moviedex.html", {})
    return HttpResponse("<h1>It works!</h1>")


def option(request):
    # return render(request, "option.html", {})
    return render(request, "options.html")


def a_select(request):
    # return render(request, "option.html", {})
    return render(request, "options.html")


def save_a(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    counter = 0

    if (history['k']['selected'] == 1):
        copyfile('filename.pickle', 'saved_game/slot_a.pickle')
        for i in history['j']:
            counter += 1
        history['k']['captured_a'] = counter
        history['k']['slot_a'] = True

    if (history['k']['selected'] == 2):
        copyfile('filename.pickle', 'saved_game/slot_b.pickle')
        for i in history['j']:
            counter += 1
        history['k']['captured_b'] = counter
        history['k']['slot_b'] = True

    if (history['k']['selected'] == 3):
        copyfile('filename.pickle', 'saved_game/slot_c.pickle')
        for i in history['j']:
            counter += 1
        history['k']['captured_c'] = counter
        history['k']['slot_c'] = True

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/save_game')


def save_bottom(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    if (history['k']['selected'] < 3):
        history['k']['selected'] += 1

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/save_game')


def save_top(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    if (history['k']['selected'] > 1):
        history['k']['selected'] -= 1

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/save_game')

def save(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    d = history['k']

    return render(request, "options_save_game.html", d)


def load(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    d = history['k']

    return render(request, "options_load_game.html", d)


def load_a(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    counter = 0

    if (history['k']['selected'] == 1):
        copyfile('saved_game/slot_a.pickle', 'filename.pickle')
        for i in history['j']:
            counter += 1
        history['k']['captured_a'] = counter
        history['k']['loaded_b'] = False
        history['k']['loaded_c'] = False
        history['k']['loaded_a'] = True
        history['k']['slot_a'] = True

    if (history['k']['selected'] == 2):
        copyfile('saved_game/slot_b.pickle', 'filename.pickle')
        for i in history['j']:
            counter += 1
        history['k']['captured_b'] = counter
        history['k']['loaded_a'] = False
        history['k']['loaded_c'] = False
        history['k']['loaded_b'] = True
        history['k']['slot_b'] = True

    if (history['k']['selected'] == 3):
        copyfile('saved_game/slot_c.pickle', 'filename.pickle')
        for i in history['j']:
            counter += 1
        history['k']['loaded_a'] = False
        history['k']['loaded_b'] = False
        history['k']['captured_c'] = counter
        history['k']['loaded_c'] = True
        history['k']['slot_c'] = True

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/load_game')


def load_top(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    if (history['k']['selected'] > 1):
        history['k']['selected'] -= 1

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/load_game')


def load_bottom(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    if (history['k']['selected'] < 3):
        history['k']['selected'] += 1

    with open('filename.pickle', 'wb') as handle:
        pickle.dump(history, handle, protocol=pickle.HIGHEST_PROTOCOL)

    return redirect('http://127.0.0.1:8000/options/load_game')


def moviedex_render(request):

    with open('filename.pickle', 'rb') as handle:
        history = pickle.load(handle)

    return render(request, "moviedex_render.html", history)
