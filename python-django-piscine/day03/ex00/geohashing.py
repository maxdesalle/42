import sys
from antigravity import geohash


def geohashing(argv):
    
    if (len(argv) != 4):
        return

    try:
        geohash(float(argv[1]), float(argv[2]), bytes(argv[3], 'utf-8'))
    except:
        print("Error, please try again with different values\nValid function call example: 'python3 geohashing.py 37.421542 -122.085589 2005-05-26-10458.68'")


if __name__ == '__main__':
    geohashing(sys.argv)
