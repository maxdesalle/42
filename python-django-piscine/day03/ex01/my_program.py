import path


def my_program():

    x = path.__file__

    while True:
        if (x.endswith("ex01/")):
            break
        else:
            x = x.rstrip(x[-1])

    d = path.Path("%s%s" % (x, "folder/"))
    f = path.Path("%s%s" % (d, "file"))

    d.makedirs_p()
    f.write_text("Quick little test to see if it works!")


if __name__ == '__main__':
    my_program()
