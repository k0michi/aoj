#include <iostream>
#include <vector>

constexpr int NIL = -1;

struct Node {
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

std::vector<Node> nodes;

int getDepth(int i) {
  if (nodes[i].parent == NIL) {
    return 0;
  } else {
    return getDepth(nodes[i].parent) + 1;
  }
}

std::string getType(int i) {
  if (nodes[i].parent == NIL) {
    return "root";
  } else if (nodes[i].left == NIL) {
    return "leaf";
  } else {
    return "internal node";
  }
}

int main() {
  int n;
  std::cin >> n;
  nodes.resize(n);

  for (int i = 0; i < n; i++) {
    int id, k;
    std::cin >> id >> k;
    int last = NIL;

    for (int j = 0; j < k; j++) {
      int c;
      std::cin >> c;

      if (j == 0) {
        nodes[id].left = c;
      } else {
        nodes[last].right = c;
      }

      nodes[c].parent = id;
      last = c;
    }
  }

  for (int i = 0; i < n; i++) {
    int p = nodes[i].parent;
    int d = getDepth(i);
    std::string type = getType(i);
    std::cout << "node " << i << ": parent = " << p << ", depth = " << d << ", "
              << type << ", [";
    int j = nodes[i].left;

    while (j != NIL) {
      std::cout << j;

      if (nodes[j].right != NIL) {
        std::cout << ", ";
      }

      j = nodes[j].right;
    }

    std::cout << ']' << std::endl;
  }

  return 0;
}