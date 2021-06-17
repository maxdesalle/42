import requests, json, dewiki, sys


def request_api(argv):
    
    if (len(argv) != 2):
        return

    r = requests.get('https://fr.wikipedia.org/w/api.php?action=parse&page={}&prop=wikitext&formatversion=2&format=json&redirects&limit=1'.format(argv[1]))
    r = json.loads(r.text)
    r = dewiki.from_string(r['parse']['wikitext'])
    print(r)
    return


if __name__ == '__main__':
    request_api(sys.argv)
