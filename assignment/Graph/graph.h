#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

class Graph{
  public:
  void LoadMatrix(std::string& filename);  
  int GetSize();
  void PrintMatrix(); 
  void PrintShortestPathWeight(int s);
  void PrintShortestPath(int s);  

  private:
  std::vector<std::vector<int>> adjacencyMatrix;   
  int size;       
};
#endif