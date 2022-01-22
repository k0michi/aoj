#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template <class T, class Container = std::vector<T>,
          class Compare = std::greater<typename Container::value_type>>
using reverse_priority_queue = std::priority_queue<T, Container, Compare>;

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
};

int n;
std::vector<Vertex> vertices;

void dijkstra() {
  reverse_priority_queue<std::pair<int, int>> prQueue;
  vertices[0].distance = 0;
  prQueue.push({0, 0});

  while (!prQueue.empty()) {
    auto [d, v] = prQueue.top();
    prQueue.pop();

    if (vertices[v].distance < d) {
      continue;
    }

    for (const Adjacency &a : vertices[v].adjacencies) {
      if (!vertices[a.to].visited &&
          vertices[v].distance + a.weight < vertices[a.to].distance) {
        vertices[a.to].distance = vertices[v].distance + a.weight;
        prQueue.push({vertices[a.to].distance, a.to});
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