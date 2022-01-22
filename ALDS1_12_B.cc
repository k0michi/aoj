#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

constexpr int Infinity = std::numeric_limits<int>::max();
constexpr int Nil = -1;

struct Adjacency {
  int to;
  int weight;
};

struct Vertex {
  std::vector<Adjacency> adjacencies;
  bool visited = false;
  int distance = Infinity;
  int parent = -1;
};

int n;
std::vector<Vertex> vertices;

int nearest() {
  int v = Nil;
  int d = Infinity;

  for (int i = 0; i < n; i++) {
    if (vertices[i].distance < d && !vertices[i].visited) {
      v = i;
      d = vertices[i].distance;
    }
  }

  return v;
}

void dijkstra() {
  vertices.resize(n);
  vertices[0].distance = 0;

  int v;
  while (v = nearest(), v != Nil) {
    for (const Adjacency &a : vertices[v].adjacencies) {
      if (!vertices[a.to].visited &&
          vertices[v].distance + a.weight < vertices[a.to].distance) {
        vertices[a.to].distance = vertices[v].distance + a.weight;
        vertices[a.to].parent = v;
      }
    }

    vertices[v].visited = true;
  }
}

int main() {
  std::cin >> n;
  vertices.reserve(n);

  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;
    std::vector<Adjacency> adjacencies(k);

    for (int j = 0; j < k; j++) {
      int vj, cj;
      std::cin >> vj >> cj;
      adjacencies[j] = {vj, cj};
    }

    vertices.push_back({std::move(adjacencies)});
  }

  dijkstra();

  for (int i = 0; i < n; i++) {
    int distance = vertices[i].distance;

    if (distance == Infinity) {
      distance = -1;
    }

    std::cout << i << ' ' << distance << std::endl;
  }

  return 0;
}