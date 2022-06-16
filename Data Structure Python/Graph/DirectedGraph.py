from Graph import Graph
from vertex import Vertex


class directed_graph(Graph):

    def __init__(self) -> None:
        super(directed_graph, self).__init__()

    def Add(self, val, adjacents: list):

        # Search for the vertex if it already exist, must be false
        if self.Search(val) == True:
            raise Exception(val, "already in graph")

        else:
            # Lopp in new vertex list
            for vertex in adjacents:
                # Search for every vertex in the vector if it already exist, must be true
                if self.Search(vertex) == False:
                    raise Exception(vertex, "is not in the graph")

            # make new vertex and push it to the graph
            newVertex: Vertex = Vertex(val, adjacents)
            self.Vertices.append(newVertex)

    # Create path to existing vertex
    def CreatePath(self, val, newAdjacents: list):

        if (self.Search(val) == False):
            raise Exception(val, "not exsit in the graph.")

        else:
            for x in newAdjacents:
                # check if x already in graph
                if (self.Search(x) == False):
                    raise Exception(x, "is not exsit in the graph.")

                else:
                    # check if x already in val adjacents
                    if (self.ReturnVertex(val).check_existence_of_value(x)):
                        raise Exception(
                            val, "and", x, "are already connected.")

                    else:
                        # add the x to val adjacents
                        temp: Vertex = self.ReturnVertex(val)
                        temp.newAdjacents(x)
                        temp.Edgs += 1

    # Add cost with other value
    def newCost(self, value_1, value_2, cost: int):

        if (self.Search(value_1) and self.Search(value_2)):

            # add the cost to the both sides
            temp_1: Vertex = self.ReturnVertex(value_1)
            if (temp_1.check_existence_of_value(value_2)):
                temp_1.costs_[value_2] = cost
            
            else:
                raise Exception(value_1, "and", value_2, "are not connected.")

        else:
            raise Exception(value_1, "or", value_2, "is not exist.")

    # Return Graph type
    def GraphType():
        return "Directed Graph"
