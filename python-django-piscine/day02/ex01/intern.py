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
