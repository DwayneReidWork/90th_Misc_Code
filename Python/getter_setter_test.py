class Vehicle:
    def __init__(self,make,model,year):
        self._make = make
        self._model = model
        self._year = year
    
    @property
    def year(self):
        return self._year
    
    @year.setter
    def year(self,value):
        self._year = value

    @property
    def model(self):
        return self._model
    
    @model.setter
    def model(self,value):
        self._model = value

    @property
    def make(self):
        return self._make
    
    @make.setter
    def make(self,value):
        self._make = value

class ElectricVehicle(Vehicle):
    def __init__(self):
        super().__init__()
        self._battery_capacity = 0
    
    def battery_capacity(self):
        return self._battery_capacity
    
    def battery_capacity(self,value):
        self.battery_capacity = value

testVals = ["Hyundai","Accent",2016]
myVic = Vehicle(testVals[0],testVals[1],testVals[2])
# print(myVic.make())
# myVic.make(testVals[0])
print(myVic.make)
print(myVic.model)
print(myVic.year)

myVic.make = "Mazda"
print(myVic.make)