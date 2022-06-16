#ifndef __Undirected_Graph
#define __Undirected_Graph

#include "Graph.hpp"
#include "Vertex.hpp"

#include <string>
#include <stdexcept>

template <typename T>
class Undirected_Graph : public Graph<T>
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
void Undirected_Graph<T>::Add(T val, std::vector<T> adjacents)
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

    // add the new vertex to to the old vertices list
    // Loop through adjacents vector in the new vertex
    for (int i = 0; i < newVertex->adjacents_.size(); i++)
    {
      Vertex<T> *temp = this->ReturnVertex(newVertex->adjacents_[i]);
      temp->newAdjacents(newVertex->value_);
    }
  }
}

// Create path to existing vertex
template <typename T>
void Undirected_Graph<T>::CreatePath(T val, std::vector<T> newAdjacents)
{
  // check if val already in graph
  if (this->Search(val) == false)
  {
    throw std::invalid_argument(std::to_string(val) + " is not exsit in he graph.");
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
          Vertex<T> *tempval = this->ReturnVertex(val);
          Vertex<T> *tempx = this->ReturnVertex(x);
          tempval->newAdjacents(x);
          tempx->newAdjacents(val);
          tempval->edgs_++;
          tempx->edgs_++;
        }
      }
    }
  }
}

// Add cost with other value
template <typename T>
void Undirected_Graph<T>::newCost(T value_1, T value_2, int cost)
{
  // check if the values are exsits in the graph
  if (this->Search(value_1) && this->Search(value_2))
  {
    // add the cost to the both sides
    Vertex<T> *temp_1 = this->ReturnVertex(value_1);
    Vertex<T> *temp_2 = this->ReturnVertex(value_2);
    if (temp_1->check_existence_of_value(value_2))
    {
      temp_1->costs_[value_2] = cost;
      temp_2->costs_[value_1] = cost;
    }
    else
    {
      throw std::invalid_argument(std::to_string(value_1) + " and " + std::to_string(value_2) + " values are not connected.");
    }
  }
  else
  {
    throw std::invalid_argument(std::to_string(value_1) + " or " + std::to_string(value_2) + " is not exist.");
  }
}

// Return Graph type
template <typename T>
std::string Undirected_Graph<T>::GraphType()
{
  return "Undirected Graph";
}

#endif
