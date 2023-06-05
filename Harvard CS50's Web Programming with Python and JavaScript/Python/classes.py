class Flight():
    def __init__(self, capacity):
        self.capacity = capacity
        self.passengers = []

    def addPassenger(self, name):
        if not self.openSeats():
            return False
        self.passengers.append(name)
        return True

    def openSeats(self):
        return self.capacity - len(self.passengers)

flight = Flight(3)

people = ["joey","stephen","kevin","john"]
for person in people: 
    success = flight.addPassenger(person)
    if success:
        print(f"Added {person} to flight successfully.")
    else: 
        print(f"Ain't no way we can get a seat for {person} though.")
