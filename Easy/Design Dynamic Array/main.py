class DynamicArray:

    def __init__(self, capacity: int):
        self.D_array = [None] * capacity
        self.capacity = capacity
        self.size = 0

    def get(self, i: int) -> int:
        return self.D_array[i]

    def set(self, i: int, n: int) -> None:
        self.D_array[i] = n

    def pushback(self, n: int) -> None:
        if self.size == self.capacity:
            self.resize()
        self.D_array[self.size] = n
        self.size += 1

    def popback(self) -> int:
        self.size -= 1
        return self.D_array[self.size]

    def resize(self) -> None:
        self.capacity = self.capacity * 2
        temp_array = [None] * self.capacity
        temp_array[: self.size] = self.D_array
        self.D_array = temp_array

    def getSize(self) -> int:
        return self.size

    def getCapacity(self) -> int:
        return self.capacity
