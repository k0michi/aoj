#include <iostream>
#include <string>

struct Node {
  int key;
  Node *prev;
  Node *next;
};

struct List {
  Node nil;

  List() {
    nil.next = &nil;
    nil.prev = &nil;
  }

  Node *begin() { return nil.next; }

  Node *end() { return &nil; }

  Node *find(int key) {
    for (auto n = begin(); n != end(); n = n->next) {
      if (n->key == key) {
        return n;
      }
    }

    return nullptr;
  }

  void insert(Node *pos, int key) {
    auto node = new Node{key, pos->prev, pos};
    pos->prev->next = node;
    pos->prev = node;
  }

  void erase(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }
};

int main() {
  int n;
  std::cin >> n;

  List list;

  for (int i = 0; i < n; i++) {
    std::string command;
    std::cin >> command;

    if (command == "insert") {
      int x;
      std::cin >> x;

      list.insert(list.begin(), x);
    } else if (command == "delete") {
      int x;
      std::cin >> x;

      auto it = list.find(x);

      if (it != nullptr) {
        list.erase(it);
      }
    } else if (command == "deleteFirst") {
      list.erase(list.begin());
    } else if (command == "deleteLast") {
      list.erase(list.end()->prev);
    }
  }

  for (auto n = list.begin(); n != list.end(); n = n->next) {
    std::cout << n->key;

    if (n != list.end()->prev) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}