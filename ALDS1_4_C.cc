#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Dictionary {
  std::vector<std::list<std::string>> table;

  Dictionary() : table(8192) {}

  void insert(const std::string &str) {
    auto &list = table[std::hash<std::string>()(str) % table.size()];
    auto result = std::find(list.begin(), list.end(), str);

    if (result == list.end()) {
      list.push_back(str);
    }
  }

  bool find(const std::string &str) {
    auto &list = table[std::hash<std::string>()(str) % table.size()];
    auto result = std::find(list.begin(), list.end(), str);

    return result != list.end();
  }
};

int main() {
  int n;
  std::cin >> n;

  Dictionary dictionary;

  for (int i = 0; i < n; i++) {
    std::string instruction, str;
    std::cin >> instruction >> str;

    if (instruction == "insert") {
      dictionary.insert(str);
    } else if (instruction == "find") {
      bool found = dictionary.find(str);

      if (found) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
  }

  return 0;
}