class Intern:

    def __init__(self, Name="My name?  I’m nobody, an intern, I have no name."):
        self.name = Name

    def __str__(self):
        return self.name

    class Coffee:
        def __str__(self):
            return "This is the worst coffee you ever tasted."

    def work(self):
        raise Exception("I’m just an intern, I can’t do that...")

    def make_coffee(self):
        return self.Coffee()


def test():

    random_intern = Intern()
    mark = Intern(Name="Mark")

    print("Random intern name:", random_intern)
    print("Mark's name:", mark)
    print("")

    print("Random intern's coffee:", random_intern.make_coffee())
    print("Mark's coffee:", mark.make_coffee())
    print("")

    try:
        random_intern.work()
    except Exception as error:
        print("Random intern's error message:", error)

    try:
        mark.work()
    except Exception as error:
        print("Mark's error message:", error)

if __name__ == '__main__':
    test()
