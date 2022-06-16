#include <iostream>

#include "UndirectedGraph.hpp"
#include "DirectedGraph.hpp"

void UnDirected_Graph_implementation();
void Directed_Graph_implementation();

int main()
{
  UnDirected_Graph_implementation();

  std::cout << "\n\n-----------------------------\n\n";

  Directed_Graph_implementation();
}

void UnDirected_Graph_implementation()
{
  // Undirected graph
  Undirected_Graph<int> UnDirectedGraph;

  std::cout << UnDirectedGraph.GraphType() << "\n";

  UnDirectedGraph.Add(1, {});
  UnDirectedGraph.Add(2, {});
  UnDirectedGraph.Add(3, {});
  UnDirectedGraph.Add(4, {});
  UnDirectedGraph.Add(5, {});
  UnDirectedGraph.Add(6, {});

  UnDirectedGraph.Display();
  std::cout << "\n";

  std::cout << std::boolalpha;
  std::cout << (UnDirectedGraph.Search(1) == true) ? "true" : "false";
  std::cout << "\n";
  std::cout << (UnDirectedGraph.Search(6) == true) ? "true" : "false";
  std::cout << "\n";

  // Creating the path between vertices
  UnDirectedGraph.CreatePath(1, {2, 4, 3});
  UnDirectedGraph.CreatePath(2, {3});
  UnDirectedGraph.CreatePath(3, {});
  UnDirectedGraph.CreatePath(4, {});
  UnDirectedGraph.CreatePath(5, {4});
  UnDirectedGraph.CreatePath(6, {2});

  UnDirectedGraph.Display();
  std::cout << "\n";

  // Adding costs between vertices
  UnDirectedGraph.newCost(1, 4, 10);
  UnDirectedGraph.newCost(1, 2, 50);
  UnDirectedGraph.newCost(1, 3, 45);
  UnDirectedGraph.newCost(2, 3, 10);
  UnDirectedGraph.newCost(4, 1, 10);
  UnDirectedGraph.newCost(4, 5, 15);
  UnDirectedGraph.newCost(6, 2, 3);

  UnDirectedGraph.Display_vertex_cost(4);

  std::cout << "edgs count for 2: " << UnDirectedGraph.ReturnVertex(2)->EdgsCount() << "\n";
}

void Directed_Graph_implementation()
{
  // Directed graph
  Directed_Graph<int> DirectedGraph;

  std::cout << "Graph type:" << DirectedGraph.GraphType() << "\n\n";

  // Adding the vertices
  DirectedGraph.Add(1, {});
  DirectedGraph.Add(2, {});
  DirectedGraph.Add(3, {});
  DirectedGraph.Add(4, {});
  DirectedGraph.Add(5, {});
  DirectedGraph.Add(6, {});

  DirectedGraph.Display();
  std::cout << "\n";

  std::cout << std::boolalpha;
  std::cout << ((DirectedGraph.Search(1) == true) ? "1 is exsit\n" : "1 is not exsit\n");
  std::cout << ((DirectedGraph.Search(7) == true) ? "7 is exsit\n" : "7 is not exsit\n");
  std::cout << "\n";

  // Creating the path between vertices
  DirectedGraph.CreatePath(1, {2, 4, 3});
  DirectedGraph.CreatePath(2, {3, 4});
  DirectedGraph.CreatePath(3, {5});
  DirectedGraph.CreatePath(4, {1, 5});
  DirectedGraph.CreatePath(5, {3, 2});
  DirectedGraph.CreatePath(6, {5});

  DirectedGraph.Display();
  std::cout << "\n";

  // Adding costs between vertices
  DirectedGraph.newCost(1, 4, 10);
  DirectedGraph.newCost(1, 2, 50);
  DirectedGraph.newCost(1, 3, 45);
  DirectedGraph.newCost(2, 3, 10);
  DirectedGraph.newCost(2, 4, 15);
  DirectedGraph.newCost(3, 5, 30);
  DirectedGraph.newCost(4, 1, 10);
  DirectedGraph.newCost(4, 5, 15);
  DirectedGraph.newCost(5, 2, 20);
  DirectedGraph.newCost(5, 3, 35);
  DirectedGraph.newCost(6, 5, 3);

  DirectedGraph.Display_vertex_cost(4);

  std::cout << "edgs count for 2: " << DirectedGraph.ReturnVertex(2)->EdgsCount() << "\n\n";
}
