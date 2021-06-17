import path


def my_program():

    my_path = path.__file__
    
    while not (my_path.endswith("ex01/")):
            my_path = my_path.rstrip(my_path[-1])

    my_folder = path.Path("%s%s" % (my_path, "folder/"))
    my_file = path.Path("%s%s" % (my_folder, "file"))

    my_folder.makedirs_p()
    my_file.write_text("Quick little test to see if it works!")
    with open("./folder/file", "r") as f:
        print(f.read())


if __name__ == '__main__':
    my_program()
