#include <iostream>
#include <string>

constexpr int NIL = -1;

struct Node {
  int key;
  int priority;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

Node *root;

Node *rotateRight(Node *t) {
  Node *s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

Node *rotateLeft(Node *t) {
  Node *s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node *insert(Node *t, int key, int priority) {
  if (t == nullptr) {
    return new Node{key, priority};
  }

  if (key == t->key) {
    return t;
  }

  if (key < t->key) {
    t->left = insert(t->left, key, priority);

    if (t->priority < t->left->priority) {
      t = rotateRight(t);
    }
  } else {
    t->right = insert(t->right, key, priority);

    if (t->priority < t->right->priority) {
      t = rotateLeft(t);
    }
  }

  return t;
}

Node *find(Node *t, int key) {
  if (t == nullptr) {
    return nullptr;
  }

  if (t->key == key) {
    return t;
  } else if (t->key > key) {
    return find(t->left, key);
  } else {
    return find(t->right, key);
  }
}

bool hasChildren(Node *t) {
  if (t->left != nullptr || t->right != nullptr) {
    return true;
  }

  return false;
}

Node *rotate(Node *t, int key) {
  if (t->left == nullptr) {
    t = rotateLeft(t);
  } else if (t->right == nullptr) {
    t = rotateRight(t);
  } else {
    if (t->left->priority > t->right->priority) {
      t = rotateRight(t);
    } else {
      t = rotateLeft(t);
    }
  }

  return t;
}

Node *remove(Node *t, int key) {
  if (t == nullptr) {
    return nullptr;
  }

  if (t->key > key) {
    t->left = remove(t->left, key);
  } else if (t->key < key) {
    t->right = remove(t->right, key);
  } else {
    if (hasChildren(t)) {
      t = rotate(t, key);
      t = remove(t, key);
    } else {
      delete t;
      t = nullptr;
    }
  }

  return t;
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
      int k, p;
      std::cin >> k >> p;
      root = insert(root, k, p);
    } else if (query == "find") {
      int k;
      std::cin >> k;
      Node *found = find(root, k);
      std::cout << (found != nullptr ? "yes" : "no") << std::endl;
    } else if (query == "delete") {
      int k;
      std::cin >> k;
      root = remove(root, k);
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