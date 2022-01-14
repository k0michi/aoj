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

Node *find(int k) {
  Node *x = root;

  while (x != nullptr && x->key != k) {
    if (x->key > k) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  return x;
}

void replace(Node *z, Node *newZ) {
  if (z->parent == nullptr) {
    root = newZ;

    if (newZ != nullptr) {
      newZ->parent = nullptr;
    }
  } else {
    if (z->parent->left == z) {
      z->parent->left = newZ;
    } else {
      z->parent->right = newZ;
    }

    if (newZ != nullptr) {
      newZ->parent = z->parent;
    }
  }

  delete z;
}

Node *getSuccessor(Node *z) {
  if (z->right != nullptr) {
    Node *y = z->right;

    while (y->left != nullptr) {
      y = y->left;
    }

    return y;
  } else {
    Node *y = z;

    while (y->parent != nullptr && y->parent->right == y) {
      y = y->parent;
    }

    return y->parent;
  }
}

void remove(Node *z) {
  if (z->left == nullptr || z->right == nullptr) {
    Node *y;

    if (z->left != nullptr) {
      y = z->left;
    } else {
      y = z->right;
    }

    replace(z, y);
  } else {
    Node *y = getSuccessor(z);
    z->key = y->key;
    remove(y);
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
    } else if (query == "find") {
      int k;
      std::cin >> k;
      Node *found = find(k);
      std::cout << (found != nullptr ? "yes" : "no") << std::endl;
    } else if (query == "delete") {
      int k;
      std::cin >> k;
      Node *found = find(k);
      remove(found);
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