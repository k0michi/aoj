#include <iostream>
#include <limits>
#include <vector>

constexpr int Infinity = std::numeric_limits<int>::max();
constexpr int Nil = -1;

struct Vertex {
  bool visited = false;
  int distance = Infinity;
  int parent = -1;
};

int n;
std::vector<std::vector<int>> A;
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

int prim() {
  vertices.resize(n);
  vertices[0].distance = 0;

  int v;
  while (v = nearest(), v != Nil) {
    vertices[v].visited = true;

    for (int w = 0; w < n; w++) {
      if (!vertices[w].visited && A[v][w] != Infinity &&
          vertices[w].distance > A[v][w]) {
        vertices[w].distance = A[v][w];
        vertices[w].parent = v;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (vertices[i].parent != Nil) {
      sum += A[i][vertices[i].parent];
    }
  }

  return sum;
}

int main() {
  std::cin >> n;
  A.resize(n, std::vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int aij;
      std::cin >> aij;

      if (aij == -1) {
        aij = Infinity;
      }

      A[i][j] = aij;
    }
  }

  std::cout << prim() << std::endl;
  return 0;
}