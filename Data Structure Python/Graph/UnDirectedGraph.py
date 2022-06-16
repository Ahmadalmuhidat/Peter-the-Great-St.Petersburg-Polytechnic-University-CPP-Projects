from Graph import Graph
from vertex import Vertex


class undirected_graph(Graph):

    def __init__(self) -> None:
        super(undirected_graph, self).__init__()

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

            # Add the new vertex to to the old vertices list
            # Loop through adjacents vector in the new vertex
            for vertex in newVertex.Adjacents:
                temp: Vertex = self.ReturnVertex(vertex)
                temp.newAdjacents(newVertex.Value)

    # Create path to existing vertex
    def CreatePath(self, val, newAdjacents: list):
        # check if val already in graph
        if (self.Search(val) == False):
            raise Exception(val, "not exsit in he graph.")

        else:
            for x in newAdjacents:
                # check if x already in graph
                if (self.Search(x) == False):
                    raise Exception(x, "is not exsit in he graph.")
                else:
                    if (self.ReturnVertex(val).check_existence_of_value(x)):
                        raise Exception(val, "and", x, "are already connected.")
                    else:
                        # add the x to val adjacents
                        tempval: Vertex = self.ReturnVertex(val)
                        tempx: Vertex = self.ReturnVertex(x)
                        tempval.newAdjacents(x)
                        tempx.newAdjacents(val)
                        tempval.Edgs += 1
                        tempx.Edgs += 1

    # Add cost with other value
    def newCost(self, value_1, value_2, cost: int):
        # check if the values are exsits in the graph
        if (self.Search(value_1) and self.Search(value_2)):
            # add the cost to the both sides
            temp_1: Vertex = self.ReturnVertex(value_1)
            temp_2: Vertex = self.ReturnVertex(value_2)
            if (temp_1.check_existence_of_value(value_2)):
                temp_1.costs_[value_2] = cost
                temp_2.costs_[value_1] = cost
            else:
                raise Exception(value_1, "and", value_2, "values are not connected.")
        else:
            raise Exception(value_1, "or", value_2, "is not exist.")

    # Return Graph type
    def GraphType(self):
        return "UnDirected Graph"
