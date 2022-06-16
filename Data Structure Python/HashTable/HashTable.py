class HashTable:

    # HashTable contstuctor
    def __init__(self, size: int):
        self.size = size
        self.hash_table = [None] * size  # fill the table with lists

    # Calculate the hash index
    def __hashFunction(self, val) -> int:
        result = self.size % val
        return result

    # add value to the table
    def AddValue(self, val):
        hashed_index = self.__hashFunction(val)
        # the cell which will save the value
        chain = self.hash_table[hashed_index]
        if chain == None:
            self.hash_table[hashed_index] = []
            self.hash_table[hashed_index].append(val)
        else:
            self.hash_table[hashed_index].append(val)

    # search and return value
    def getValue(self, val):
        hashed_index = self.__hashFunction(val)
        result = None
        # check if the chain exist
        if self.hash_table[hashed_index] != None:
            # look for the value in the chain
            for i in self.hash_table[hashed_index]:
                if i == val:
                    result = i
                    break
            if result == None:
                raise Exception("value is not exist")
            else:
                return result
        else:
            raise Exception("value is not exist")

    # delete value from the table
    def deleteValue(self, val):
        hashed_index = self.__hashFunction(val)
        target = None
        # look for the value in the chain
        if self.hash_table[hashed_index] != None:
            for i in self.hash_table[hashed_index]:
                if i == val:
                    target = val
                    break
            if target != None:
                self.hash_table[hashed_index].remove(val)
            else:
                raise Exception("can't delete the value because it is exist")
        else:
            raise Exception("value is not exist")

    # display the table content
    def Display(self):
        for i in range(len(self.hash_table)):
            print(i, "-->", self.hash_table[i])
