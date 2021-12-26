#include <iostream>
#include <vector>

constexpr int NIL = -1;

struct Node {
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

std::vector<Node> nodes;

void walkPreorder(int i) {
  if (i == NIL) {
    return;
  }

  std::cout << ' ' << i;
  walkPreorder(nodes[i].left);
  walkPreorder(nodes[i].right);
}

void walkInorder(int i) {
  if (i == NIL) {
    return;
  }

  walkInorder(nodes[i].left);
  std::cout << ' ' << i;
  walkInorder(nodes[i].right);
}

void walkPostorder(int i) {
  if (i == NIL) {
    return;
  }

  walkPostorder(nodes[i].left);
  walkPostorder(nodes[i].right);
  std::cout << ' ' << i;
}

int main() {
  int n;
  std::cin >> n;
  nodes.resize(n);

  for (int i = 0; i < n; i++) {
    int id, left, right;
    std::cin >> id >> left >> right;
    nodes[id].left = left;
    nodes[left].parent = id;
    nodes[id].right = right;
    nodes[right].parent = id;
  }

  int root;

  for (int i = 0; i < n; i++) {
    if (nodes[i].parent == NIL) {
      root = i;
      break;
    }
  }

  std::cout << "Preorder" << std::endl;
  walkPreorder(root);
  std::cout << std::endl;
  std::cout << "Inorder" << std::endl;
  walkInorder(root);
  std::cout << std::endl;
  std::cout << "Postorder" << std::endl;
  walkPostorder(root);
  std::cout << std::endl;
  return 0;
}