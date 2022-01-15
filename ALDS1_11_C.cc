#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Vertex {
  std::vector<int> adjacencies;
  bool visited;
  int distance;
};

constexpr int Unreachable = -1;

std::vector<Vertex> vertices;

void bfs(int vertexID) {
  std::queue<int> queue;

  vertices[vertexID].visited = true;
  vertices[vertexID].distance = 0;
  queue.push(vertexID);

  while (!queue.empty()) {
    int v = queue.front();
    queue.pop();

    for (int w : vertices[v].adjacencies) {
      if (!vertices[w].visited) {
        vertices[w].visited = true;
        vertices[w].distance = vertices[v].distance + 1;
        queue.push(w);
      }
    }
  }
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

    vertices.push_back({std::move(adjacencies), false, Unreachable});
  }

  bfs(0);

  for (int i = 0; i < n; i++) {
    Vertex &vertex = vertices[i];
    std::cout << i + 1 << ' ' << vertex.distance << std::endl;
  }

  return 0;
}