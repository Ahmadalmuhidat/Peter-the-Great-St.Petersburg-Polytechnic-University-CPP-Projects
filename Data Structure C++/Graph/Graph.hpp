#ifndef __GRAPH
#define __GRAPH

#include "Vertex.hpp"

#include <string>
#include <vector>
#include <iostream>

template <typename T>
class Graph
{
public:
  // Add vertex to the graph
  virtual void Add(T val, std::vector<T> adjacents) = 0;

  // Create path to existing vertex
  virtual void CreatePath(T val, std::vector<T> newAdjacents) = 0;

  // Add cost with other value
  virtual void newCost(T value_1, T value_2, int cost) = 0;

  // Return Graph type
  virtual std::string GraphType() = 0;

  // Display graph
  virtual void Display();

  // Search for vertex
  virtual bool Search(T val);

  // Search and return vertex
  virtual Vertex<T> *ReturnVertex(T val);

  // Display the costs for specific vertex
  virtual void Display_vertex_cost(T val);

  std::vector<Vertex<T>> vertices_; // Vertices inside the graph
};

// Display graph: vertex: [Vertices that connected to the Vertex]
template <typename T>
void Graph<T>::Display()
{
  std::cout << "Graph content: \n";
  for (int i = 0; i < this->vertices_.size(); i++)
  {
    // Get the vertex
    std::cout << this->vertices_[i].value_ << " --> ";

    // Get the vertices list and display them in row
    for (auto it = this->vertices_[i].adjacents_.begin(); it != this->vertices_[i].adjacents_.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  }
}

// Search for vertex
template <typename T>
bool Graph<T>::Search(T val)
{
  // Loop inisde the vertices
  for (int i = 0; i < this->vertices_.size(); i++)
  {
    // Check if the value equal the wanted value
    if (this->vertices_[i].value_ == val)
    {
      return true;
    }
  }
  return false;
}

// Search and return vertex
template <typename T>
Vertex<T> *Graph<T>::ReturnVertex(T val)
{
  Vertex<T> *result = nullptr;

  for (int i = 0; i < this->vertices_.size(); i++)
  {
    // Check if the value_ equal the wanted value_
    if (this->vertices_[i].value_ == val)
    {
      result = &this->vertices_[i];
    }
  }
  return result;
}

// Display the costs for specific vertex
template <typename T>
void Graph<T>::Display_vertex_cost(T val)
{
  Vertex<T> *temp = this->ReturnVertex(val);
  temp->Display_costs();
}
#endif
