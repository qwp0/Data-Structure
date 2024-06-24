#include "graph.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

void Graph::LoadMatrix(string &filename)
{
  ifstream fileInput(filename);
  fileInput >> size;
  adjacencyMatrix.resize(size, vector<int>(size, 999));

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      fileInput >> adjacencyMatrix[i][j];
    }
  }
  fileInput.close();
}
void Graph::PrintMatrix()
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << adjacencyMatrix[i][j] << " ";
    }
    cout << endl;
  }
}
int Graph::GetSize()
{
  return size;
}
void Graph::PrintShortestPathWeight(int s)
{
  vector<int> Dist(size, 999);
  priority_queue<pair<int, int>> Q;
  Dist[s] = 0;
  Q.push(pair<int, int>(0, s));

  while (!Q.empty())
  {
    int d = Q.top().first;
    int u = Q.top().second;
    Q.pop();
    for (int i = 0; i < size; i++)
    {
      if (adjacencyMatrix[u][i] != 999 && Dist[u] + adjacencyMatrix[u][i] < Dist[i])
      {
        Dist[i] = Dist[u] + adjacencyMatrix[u][i];
        Q.push(pair<int, int>(Dist[i], i));
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    cout << Dist[i] << endl;
  }
}
void Graph::PrintShortestPath(int s)
{
  vector<int> Dist(size, 999);
  vector<int> parent(size, -1);
  priority_queue<pair<int, int>> Q;

  Dist[s] = 0;
  Q.push(pair<int, int>(0, s));

  while (!Q.empty())
  {
    int d = Q.top().first;
    int u = Q.top().second;
    Q.pop();
    for (int i = 0; i < size; i++)
    {
      if (adjacencyMatrix[u][i] != 999 && Dist[u] + adjacencyMatrix[u][i] < Dist[i])
      {
        Dist[i] = Dist[u] + adjacencyMatrix[u][i];
        parent[i] = u;
        Q.push(pair<int, int>(Dist[i], i));
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (i != s)
    {
      int curVertex = i;
      vector<int> path;
      while (curVertex != -1)
      {
        path.push_back(curVertex);
        curVertex = parent[curVertex];
      }
      for (int j = path.size() - 1; j >= 0; j--)
      {
        cout << path[j] << " ";
      }
      cout << endl;
    }
  }
}
