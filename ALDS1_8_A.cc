#include <iostream>
#include <string>

constexpr int NIL = -1;

struct Node {
  int key;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

Node *root;

void insert(Node *z) {
  Node *y = nullptr;
  Node *x = root;

  while (x != nullptr) {
    y = x;

    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == nullptr) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void release(Node *node) {
  if (node != nullptr) {
    release(node->left);
    release(node->right);
    delete node;
  }
}

void walkPreorder(Node *node) {
  if (node == nullptr) {
    return;
  }

  std::cout << ' ' << node->key;
  walkPreorder(node->left);
  walkPreorder(node->right);
}

void walkInorder(Node *node) {
  if (node == nullptr) {
    return;
  }

  walkInorder(node->left);
  std::cout << ' ' << node->key;
  walkInorder(node->right);
}

int main() {
  int m;
  std::cin >> m;

  for (int i = 0; i < m; i++) {
    std::string query;
    std::cin >> query;

    if (query == "insert") {
      int k;
      std::cin >> k;
      insert(new Node{k});
    } else if (query == "print") {
      walkInorder(root);
      std::cout << std::endl;
      walkPreorder(root);
      std::cout << std::endl;
    }
  }

  release(root);
  return 0;
}