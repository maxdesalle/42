import requests, json, dewiki, sys


def request_api(argv):
    
    test = {
        "format": "json",
        "action": "query",
        "generator": "prefixsearch",
        "gpslimit": "1",
        "prop": "revisions",
        "rvprop": "content",
        "redirects": "",
        "gpssearch": "Elon Musk"
    }

    r = requests.get('https://en.wikipedia.org/w/api.php', test)
    print(r.text)


if __name__ == '__main__':
    request_api(sys.argv)
