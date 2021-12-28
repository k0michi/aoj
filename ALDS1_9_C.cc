#include <iostream>
#include <string>
#include <utility>
#include <vector>

int parent(int i) { return i / 2; }

int left(int i) { return 2 * i; }

int right(int i) { return 2 * i + 1; }

void maxHeapify(std::vector<int> &S, int i) {
  int H = S.size();
  int l = 2 * i;
  int r = 2 * i + 1;
  int largest;

  if (l <= H && S[l - 1] > S[i - 1]) {
    largest = l;
  } else {
    largest = i;
  }

  if (r <= H && S[r - 1] > S[largest - 1]) {
    largest = r;
  }

  if (largest != i) {
    std::swap(S[i - 1], S[largest - 1]);
    maxHeapify(S, largest);
  }
}

void heapIncreaseKey(std::vector<int> &S, int k) {
  S.push_back(k);
  int i = S.size();

  while (i > 1 && S[i - 1] > S[parent(i) - 1]) {
    std::swap(S[i - 1], S[parent(i) - 1]);
    i = parent(i);
  }
}

int heapExtractMax(std::vector<int> &S) {
  int H = S.size();
  int max = S[0];
  S[0] = S[H - 1];
  S.pop_back();
  maxHeapify(S, 1);
  return max;
}

int main() {
  std::vector<int> S;
  std::string query;

  while (std::cin >> query, query != "end") {
    if (query == "insert") {
      int k;
      std::cin >> k;
      heapIncreaseKey(S, k);
    } else if (query == "extract") {
      std::cout << heapExtractMax(S) << std::endl;
    }
  }

  return 0;
}