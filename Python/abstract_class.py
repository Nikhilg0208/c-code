from abc import ABC, abstractmethod

class Base(ABC):
    
    def fun1(self):
        print("base class")
    
    @abstractmethod
    def fun2(self):
        pass

class Deri(Base):

    def fun2(self):
        print("derived class")

obj=Deri()
obj.fun1()