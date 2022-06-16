#ifndef __Vertex
#define __Vertex

#include <map>
#include <vector>
#include <iostream>

template <typename T>
struct Vertex
{
  T value_;                  // Vertex value
  std::vector<T> adjacents_; // adjacents that connected to the Vertex
  int edgs_;                 // Number of edgs
  std::map<T, int> costs_;   // Distance from vertex to another

  // Vertex constructor
  Vertex(T val, std::vector<T> adj);

  // Return the number of edgs
  int EdgsCount();

  // Add new adjacents to the vector
  void newAdjacents(T val);

  // Display costs
  void Display_costs();

  // check existence of the passed value in adjacents list
  bool check_existence_of_value(T val);
};

template <typename T>
Vertex<T>::Vertex(T val, std::vector<T> adj):
  value_(val),
  adjacents_(adj)
  {
    this->edgs_ = this->adjacents_.size();
  }

// Display costs
template <typename T>
void Vertex<T>::Display_costs()
{
  std::cout << this->value_ << " costs are: \n";
  for (auto x : this->costs_)
  {
    std::cout << x.first << " --> " << x.second;
    std::cout << "\n";
  }
  std::cout << "\n";
}

// Return the number of edgs
template <typename T>
int Vertex<T>::EdgsCount()
{
  return this->edgs_;
}

// add new adjacents to the vector
template <typename T>
void Vertex<T>::newAdjacents(T val)
{
  this->adjacents_.push_back(val);
  this->edgs_ += 1;
}

// check existence of the passed value
template <typename T>
bool Vertex<T>::check_existence_of_value(T val)
{
  for (T x : this->adjacents_)
  {
    if (x == val)
    {
      return true;
    }
  }
  return false;
}
#endif
