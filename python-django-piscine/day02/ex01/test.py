import intern


def test():
    random_intern = intern.Intern()
    mark = intern.Intern(Name="Mark")

    print(random_intern)
    print(mark)
    print(mark.make_coffee())

    try:
        mark.work()
    except Exception as error:
            print(error)


if __name__ == '__main__':
    test()
