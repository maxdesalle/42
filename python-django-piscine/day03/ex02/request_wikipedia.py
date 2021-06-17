import requests, json, dewiki, sys


def request_api(argv):
    
    if (len(argv) != 2):
        return
    
    try:
        r = requests.get('https://en.wikipedia.org/w/api.php?action=parse&page={}&prop=wikitext&formatversion=2&format=json&redirects&limit=1'.format(argv[1]))
        r = json.loads(r.text)
        r = dewiki.from_string(r['parse']['wikitext'])
        file_name = argv[1].replace(" ", "_")
        with open (file_name + '.wiki', 'w') as w:
            w.write(r)
    except:
        print("Error\nPlease try again with a valid search result")


if __name__ == '__main__':
    request_api(sys.argv)
