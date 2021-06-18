# DOES NOT WORK!!!

from bs4 import BeautifulSoup
import requests, sys


def findlink(string, option):

    baracuda = ""
    result = []

    base_url = "https://en.wikipedia.org"

    if (option == 1):
        response = requests.get("https://en.wikipedia.org/wiki/Special:Search/{}".format(string))
    else:
        response = requests.get(string)

    soup = BeautifulSoup(response.content, 'html.parser')
    test = soup.select_one("p a[href]")
    if (not test):
        return 
    if "Help:" not in str(test) and "#" not in str(test).casefold():
        result = test

    if "help:" in str(test).casefold() or "#" in str(test).casefold():
        test = test.find_next_siblings("a")
        for i in range(len(test)):
            if "help:" not in str(test[i]).casefold() and "<i" not in str(test[i].parent) and "<sup" not in str(test[i].parent):
                    result = test[i]
                    break
    
    if (len(result) > 0):
        baracuda = base_url + result['href']
    return baracuda


def duplicheck(history):


    history_set = set(history)
    return len(history) != len(history_set)


def roads_to_philosophy(argv):

    if (len(argv) != 2):
        print("Error\nPlease provide only one argument aside from the Python file")
        return

    history = []
    baracuda = findlink(argv[1], 1)
    if (baracuda == "https://en.wikipedia.org/wiki/Wikipedia:Stub"):
        print("Invalid search")
        return
    original_request = baracuda

    while True:
        if not baracuda:
            print("It leads to a dead end !")
            return
        history.append(baracuda)
        if ("https://en.wikipedia.org/wiki/Philosophy" == baracuda):
            print(len(history), "roads from", original_request, "to philosophy")
            break
        print(history)
        if (duplicheck(history) == 1):
            print("It leads to an infinite loop !")
            return
        baracuda = findlink(baracuda, 0)
        if not baracuda:
            print("It leads to a dead end !")
            return


if __name__ == '__main__':
    roads_to_philosophy(sys.argv)
