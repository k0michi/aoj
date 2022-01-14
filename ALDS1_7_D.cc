#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

constexpr int NIL = -1;

struct Node {
  int parent = NIL;
  int left = NIL;
  int right = NIL;
};

int index = 0;
std::vector<int> preorder;
std::vector<int> inorder;
std::vector<int> postorder;

void reconstruct(int left, int right) {
  if (left >= right) {
    return;
  }

  int key = preorder[index];
  index++;
  int mid =
      std::distance(inorder.begin(), find(inorder.begin(), inorder.end(), key));

  reconstruct(left, mid);
  reconstruct(mid + 1, right);
  postorder.push_back(key);
}

int main() {
  int n;
  std::cin >> n;
  preorder.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> preorder[i];
  }

  inorder.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> inorder[i];
  }

  postorder.reserve(n);
  reconstruct(0, n);

  for (int i = 0; i < n; i++) {
    std::cout << postorder[i];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}