def my_var():
    a = 42
    print(a, "est de type", a.__class__)
    a = "42"
    print(a, "est de type", a.__class__)
    a = "quarante-deux"
    print(a, "est de type", a.__class__)
    a = 42.0
    print(a, "est de type", a.__class__)
    a = True
    print(a, "est de type", a.__class__)
    a = [42]
    print(a, "est de type", a.__class__)
    a = {42: 42}
    print(a, "est de type", a.__class__)
    a = (42,)
    print(a, "est de type", a.__class__)
    a = set()
    print(a, "est de type", a.__class__)

if __name__ == '__main__':
    my_var()
