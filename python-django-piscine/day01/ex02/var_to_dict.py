def reverse_mapping(old_dict):

    new_dict = {}

    for key, value in old_dict.items():
        if value in new_dict:
            new_dict[value].append(key)
        else:
            new_dict[value] = [key]

    return new_dict


def dict_print(my_dict):

    for key, values in my_dict.items():
        counter = 1
        print(key, end=" ")
        print(":", end=" ")
        for value in values:
            if counter != len(values):
                print(value, end=" ")
            else:
                print(value)
            counter += 1


def var_to_dict():

    d = [
    ('Hendrix','1942'),
    ('Allman','1946'),
    ('King','1925'),
    ('Clapton','1945'),
    ('Johnson','1911'),
    ('Berry','1926'),
    ('Vaughan','1954'),
    ('Cooder','1947'),
    ('Page','1944'),
    ('Richards','1943'),
    ('Hammett','1962'),
    ('Cobain','1967'),
    ('Garcia','1942'),
    ('Beck','1944'),
    ('Santana','1947'),
    ('Ramone','1948'),
    ('White','1975'),
    ('Frusciante','1970'),
    ('Thompson','1949'),
    ('Burton','1939')
    ]
    
    my_dict = dict(d)
    my_dict = reverse_mapping(my_dict)
    dict_print(my_dict)

if __name__ == '__main__':
    var_to_dict()
