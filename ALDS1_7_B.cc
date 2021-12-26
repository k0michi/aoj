#include <algorithm>
#include <iostream>
#include <vector>

constexpr int NIL = -1;

struct Node {
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

std::vector<Node> nodes;

int getSibling(int i) {
  if (nodes[i].parent == NIL) {
    return NIL;
  }

  Node &parent = nodes[nodes[i].parent];

  if (parent.left != i && parent.left != NIL) {
    return parent.left;
  } else if (parent.right != i && parent.right != NIL) {
    return parent.right;
  } else {
    return NIL;
  }
}

int getDegree(int i) {
  int degree = 0;

  if (nodes[i].left != NIL) {
    degree++;
  }

  if (nodes[i].right != NIL) {
    degree++;
  }

  return degree;
}

int getDepth(int i) {
  if (nodes[i].parent == NIL) {
    return 0;
  } else {
    return getDepth(nodes[i].parent) + 1;
  }
}

int getHeight(int i) {
  int heightLeft = 0, heightRight = 0;

  if (nodes[i].left != NIL) {
    heightLeft = getHeight(nodes[i].left) + 1;
  }

  if (nodes[i].right != NIL) {
    heightRight = getHeight(nodes[i].right) + 1;
  }

  return std::max(heightLeft, heightRight);
}

std::string getType(int i) {
  if (nodes[i].parent == NIL) {
    return "root";
  } else if (nodes[i].left == NIL && nodes[i].right == NIL) {
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
    int id, left, right;
    std::cin >> id >> left >> right;
    nodes[id].left = left;
    nodes[left].parent = id;
    nodes[id].right = right;
    nodes[right].parent = id;
  }

  for (int i = 0; i < n; i++) {
    int p = nodes[i].parent;
    int s = getSibling(i);
    int deg = getDegree(i);
    int dep = getDepth(i);
    int h = getHeight(i);
    std::string type = getType(i);
    std::cout << "node " << i << ": parent = " << p << ", sibling = " << s
              << ", degree = " << deg << ", depth = " << dep
              << ", height = " << h << ", " << type << std::endl;
  }

  return 0;
}