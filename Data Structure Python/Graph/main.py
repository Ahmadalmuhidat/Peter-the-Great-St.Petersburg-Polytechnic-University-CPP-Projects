from DirectedGraph import directed_graph
from UnDirectedGraph import undirected_graph
from TopologicalSort import topologicalSort
from Depth_First_Search_Traversal import Depth_First_Search_Traversal

def UnDirected_Graph_implementation():

    # Undirected
    UnDirectedGraph: directed_graph = undirected_graph()

    # Adding the vertices
    UnDirectedGraph.Add(1, [])
    UnDirectedGraph.Add(2, [])
    UnDirectedGraph.Add(3, [])
    UnDirectedGraph.Add(4, [])
    UnDirectedGraph.Add(5, [])
    UnDirectedGraph.Add(6, [])

    UnDirectedGraph.Display()

    print(UnDirectedGraph.Search(2))
    print(UnDirectedGraph.Search(10))

    # Creating the path between vertices
    UnDirectedGraph.CreatePath(1, [2, 4, 3])
    UnDirectedGraph.CreatePath(2, [3])
    UnDirectedGraph.CreatePath(5, [4])
    UnDirectedGraph.CreatePath(6, [2])

    UnDirectedGraph.Display()

    # Adding costs between vertices
    UnDirectedGraph.newCost(1, 4, 10)
    UnDirectedGraph.newCost(1, 2, 50)
    UnDirectedGraph.newCost(1, 3, 45)
    UnDirectedGraph.newCost(2, 3, 10)
    UnDirectedGraph.newCost(4, 1, 10)
    UnDirectedGraph.newCost(4, 5, 15)
    UnDirectedGraph.newCost(6, 2, 3)

    UnDirectedGraph.Display_vertex_cost(4)

    print("edges count for 2:", UnDirectedGraph.ReturnVertex(2).EdgsCount())

    topologicalSort(UnDirectedGraph)


def Directed_Graph_implementation():

    # Directed
    DirectedGraph: directed_graph = directed_graph()

    # Adding the vertices
    DirectedGraph.Add(1, [])
    DirectedGraph.Add(2, [])
    DirectedGraph.Add(3, [])
    DirectedGraph.Add(4, [])
    DirectedGraph.Add(5, [])
    DirectedGraph.Add(6, [])

    DirectedGraph.Display()

    print(DirectedGraph.Search(2))
    print(DirectedGraph.Search(10))

    # Creating the path between vertices
    DirectedGraph.CreatePath(1, [2, 4, 3])
    DirectedGraph.CreatePath(2, [3, 4])
    DirectedGraph.CreatePath(3, [5])
    DirectedGraph.CreatePath(4, [1, 5])
    DirectedGraph.CreatePath(5, [3, 2])
    DirectedGraph.CreatePath(6, [5])

    DirectedGraph.Display()

    # Adding costs between vertices
    DirectedGraph.newCost(1, 4, 10)
    DirectedGraph.newCost(1, 2, 50)
    DirectedGraph.newCost(1, 3, 45)
    DirectedGraph.newCost(2, 3, 10)
    DirectedGraph.newCost(2, 4, 15)
    DirectedGraph.newCost(3, 5, 30)
    DirectedGraph.newCost(4, 1, 10)
    DirectedGraph.newCost(4, 5, 15)
    DirectedGraph.newCost(5, 2, 20)
    DirectedGraph.newCost(5, 3, 35)
    DirectedGraph.newCost(6, 5, 3)

    DirectedGraph.Display_vertex_cost(4)

    print("edges count for 2:", DirectedGraph.ReturnVertex(2).EdgsCount())

    print("topological Sort: ", end=" ") 
    topologicalSort(DirectedGraph)

    print("\nDepth First Search Traversal: ", end=" ")
    Depth_First_Search_Traversal(DirectedGraph)


if __name__ == '__main__':

    UnDirected_Graph_implementation()

    print("\n" * 2)

    Directed_Graph_implementation()
