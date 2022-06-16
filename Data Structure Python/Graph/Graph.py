from abc import abstractmethod, ABC
from vertex import Vertex


class Graph(ABC):

    # Graph constructor
    def __init__(self) -> None:
        self.Vertices = []  # Vertices inside the graph

    # Add vertex to the graph
    @abstractmethod
    def Add(self, val, adjacents: list):
        pass

    # Create path to existing vertex
    @abstractmethod
    def CreatePath(self, val, newAdjacents: list):
        pass

    # Add cost with other value
    @abstractmethod
    def newCost(self, value_1, value_2, cost: int):
        pass

    # Return Graph type
    @abstractmethod
    def GraphType(self):
        pass

    # Display graph
    def Display(self):

        # Loop inisde the vertices
        vertex: Vertex
        for vertex in self.Vertices:
            # print the value and the connected vertices list
            print(vertex.Value, " -> ", vertex.Adjacents)

    # Search for vertex, return bool
    def Search(self, val) -> bool:
        # Loop inisde the vertices, True if exist, False if not
        vertex: Vertex
        for vertex in self.Vertices:
            if vertex.Value == val:
                return True
        return False

    # Search and return vertex
    def ReturnVertex(self, val) -> Vertex:

        result: Vertex = None
        # Loop inisde the vertices
        vertex: Vertex
        for vertex in self.Vertices:
            # address the result target vertex
            if vertex.Value == val:
                result = vertex
                continue
            else:
                pass
        return result

    # Display the costs for specific vertex
    def Display_vertex_cost(self, val):
        temp: Vertex = self.ReturnVertex(val)
        temp.Display_costs()
