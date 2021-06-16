class HotBeverage(object):

    def __init__(self, price = 0.30, name = "hot beverage"):
        self.price = price
        self.name = name

    def description(self):
        return "Just some hot water in a cup."
    
    def __str__(self):
        return """
name : %s
price : %0.2f
description : %s""" % (self.name, self.price, self.description())


class Coffee(HotBeverage):

    def __init__(self, price = 0.40, name = "coffee"):
        HotBeverage.__init__(self, price, name)

    def description(self):
        return "A coffee, to stay awake."
    

class Tea(HotBeverage):

    def __init__(self, price = 0.30, name = "tea"):
        HotBeverage.__init__(self, price, name)


class Chocolate(HotBeverage):

    def __init__(self, price = 0.50, name = "chocolate"):
        HotBeverage.__init__(self, price, name)

    def description(self):
        return "Chocolate, sweet chocolate..."


class Cappuccino(HotBeverage):

    def __init__(self, price = 0.45, name = "cappucino"):
        HotBeverage.__init__(self, price, name)

    def description(self):
        return "Un po’ di Italia nella sua tazza!"


def test():

    hot_beverage = HotBeverage()
    coffee = Coffee()
    tea = Tea()
    chocolate = Chocolate()
    cappuccino = Cappuccino()

    print("--- Hot Beverage ---", hot_beverage)
    print("\n--- Coffee ---", coffee)
    print("\n--- Tea ---", tea)
    print("\n--- Chocolate ---", chocolate)
    print("\n--- Cappuccino ---", cappuccino)


if __name__ == '__main__':
    test()
