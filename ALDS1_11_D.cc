#include <iostream>
#include <vector>

constexpr int Nil = -1;

struct Vertex {
  std::vector<int> adjacencies;
  int group = Nil;
};

std::vector<Vertex> vertices;

void dfs(int v, int group) {
  Vertex &vertex = vertices[v];
  vertex.group = group;

  for (int w : vertex.adjacencies) {
    if (vertices[w].group == Nil) {
      dfs(w, group);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vertices.resize(n);

  for (int i = 0; i < m; i++) {
    int s, t;
    std::cin >> s >> t;
    vertices[s].adjacencies.push_back(t);
    vertices[t].adjacencies.push_back(s);
  }

  int group = 0;

  for (int i = 0; i < n; i++) {
    if (vertices[i].group == Nil) {
      dfs(i, group);
      group++;
    }
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int s, t;
    std::cin >> s >> t;
    std::cout << (vertices[s].group == vertices[t].group ? "yes" : "no")
              << std::endl;
  }

  return 0;
}