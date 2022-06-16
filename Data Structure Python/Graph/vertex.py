class Vertex:

    # Vertex constructor
    def __init__(self, value, adjacents: list) -> None:

        self.Value = value  # Vertex value
        self.Adjacents: list = adjacents  # Vertices that connected to the Vertex
        self.Edgs = len(self.Adjacents)
        self.costs_ = dict()

    # Return the number of edgs
    def EdgsCount(self) -> int:
        return self.Edgs

    # Add new adjacents to the vector
    def newAdjacents(self,
                     val):
        self.Adjacents.append(val)
        # add the new adjacent to the edgs count
        self.Edgs += 1

    # Display costs
    def Display_costs(self):
        print(self.Value, "costs are:")
        i: dict
        for i in self.costs_:
            print(i, "-->", self.costs_[i])

    # check existence of the passed value in adjacents list
    def check_existence_of_value(self, val) -> bool:
        for i in self.Adjacents:
            if i == val:
                return True
        return False
