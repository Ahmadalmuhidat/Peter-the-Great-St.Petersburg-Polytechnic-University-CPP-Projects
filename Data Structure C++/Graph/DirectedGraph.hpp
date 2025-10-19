#ifndef __Directed_Graph
#define __Directed_Graph

#include "Graph.hpp"

#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
class Directed_Graph : public Graph<T>
{
public:
  // Add vertex to the graph
  void Add(T val, std::vector<T> adjacents) override;

  // Create path to existing vertex
  void CreatePath(T val, std::vector<T> newAdjacents) override;

  // Add cost with other value
  void newCost(T value_1, T value_2, int cost) override;

  // Return Graph type
  std::string GraphType() override;
};

// Add vertex to the graph
template <typename T>
void Directed_Graph<T>::Add(T val, std::vector<T> adjacents)
{
  // Search for the vertex if it already exist, must be false
  if (this->Search(val) == true)
  {
    throw std::invalid_argument(std::to_string(val) + " already in graph.");
  }
  else
  {
    // Search for every vertex in the vector if it already exist, must be true
    for (auto it : adjacents)
    {
      if (this->Search(it) == false)
      {
        throw std::invalid_argument(std::to_string(it) + " is not exsit in the graph.");
      }
    }
    // make new vertex and push it to the graph
    Vertex<T> *newVertex = new Vertex<T>(val, adjacents);
    this->vertices_.push_back(*newVertex);
  }
}

// Create path to existing vertex
template <typename T>
void Directed_Graph<T>::CreatePath(T val, std::vector<T> newAdjacents)
{
  // check if val already in graph
  if (this->Search(val) == false)
  {
    throw std::invalid_argument(std::to_string(val) + " not exsit in the graph.");
  }
  else
  {
    for (auto x : newAdjacents)
    {
      // check if x already in graph
      if (this->Search(x) == false)
      {
        throw std::invalid_argument(std::to_string(x) + " is not exsit in the graph.");
      }
      else
      {
        // check if x already in val adjacents
        if (this->ReturnVertex(val)->check_existence_of_value(x))
        {
          throw std::invalid_argument(std::to_string(val) + " and " + std::to_string(x) + " are already connected.");
        }
        else
        {
          // add the x to val adjacents
          Vertex<T> *temp = this->ReturnVertex(val);
          temp->newAdjacents(x);
          temp->edgs_++;
        }
      }
    }
  }
}

// Add cost with other value
template <typename T>
void Directed_Graph<T>::newCost(T value_1, T value_2, int cost)
{
  if (this->Search(value_1) && this->Search(value_2))
  {
    // add the cost to the both sides
    Vertex<T> *temp_1 = this->ReturnVertex(value_1);
    if (temp_1->check_existence_of_value(value_2))
    {
      temp_1->costs_[value_2] = cost;
    }
    else
    {
      throw std::invalid_argument(std::to_string(value_1) + " and " + std::to_string(value_2) + " are not connected.");
    }
  }
  else
  {
    throw std::invalid_argument(std::to_string(value_1) + " or " + std::to_string(value_2) + " is not exist.");
  }
}

// Return Graph type
template <typename T>
std::string Directed_Graph<T>::GraphType()
{
  return "Directed Graph";
}

#endif
