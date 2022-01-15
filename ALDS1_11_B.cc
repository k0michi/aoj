#include <algorithm>
#include <iostream>
#include <vector>

struct Vertex {
  std::vector<int> adjacencies;
  bool visited;
  int discoveredAt;
  int finishedAt;
};

std::vector<Vertex> vertices;
int timestamp;

void dfs(int vertexID) {
  Vertex &vertex = vertices[vertexID];
  vertex.visited = true;
  vertex.discoveredAt = timestamp;
  timestamp++;

  for (int v : vertex.adjacencies) {
    if (!vertices[v].visited) {
      dfs(v);
    }
  }

  vertex.finishedAt = timestamp;
  timestamp++;
}

int main() {
  int n;
  std::cin >> n;
  vertices.reserve(n);

  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;
    std::vector<int> adjacencies(k);

    for (int j = 0; j < k; j++) {
      int v;
      std::cin >> v;
      adjacencies[j] = v - 1;
    }

    vertices.push_back({std::move(adjacencies), false});
  }

  timestamp = 1;

  for (int i = 0; i < n; i++) {
    if (!vertices[i].visited) {
      dfs(i);
    }
  }

  for (int i = 0; i < n; i++) {
    Vertex &vertex = vertices[i];
    std::cout << i + 1 << ' ' << vertex.discoveredAt << ' ' << vertex.finishedAt
              << std::endl;
  }

  return 0;
}