import random
from beverages import HotBeverage, Coffee, Tea, Chocolate, Cappuccino


class CoffeeMachine(object):

    def __init__(self):
        self.servings = 0

    class EmptyCup(HotBeverage):

        def __init__(self, price = 0.90, name = "empty cup"):
            HotBeverage.__init__(self, price, name)

        def description(self):
            return "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):

        def __init__(self):
            Exception.__init__(self, "This coffee machine has to be repaired.")

    def repair(self):
        self.servings = 0

    def serve(self, uparam):
        if (self.servings >= 10):
            raise self.BrokenMachineException()
        else:
            self.servings += 1
            return (random.choice([uparam, self.EmptyCup()]))


def test():
   
    i = 0
    option = [HotBeverage(), Coffee(), Tea(), Chocolate(), Cappuccino()]
    machine = CoffeeMachine()

    while (i < 25):
        try:
            print(machine.serve(random.choice(option)))
        except Exception as error:
            print("Broken machine's error message:", error)
        if i == 15:
            machine.repair()
        i += 1


if __name__ == '__main__':
    test()
