#include <iostream>
#include <utility>
#include <vector>

void maxHeapify(std::vector<int> &A, int i) {
  int H = A.size();
  int l = 2 * i;
  int r = 2 * i + 1;
  int largest;

  if (l <= H && A[l - 1] > A[i - 1]) {
    largest = l;
  } else {
    largest = i;
  }

  if (r <= H && A[r - 1] > A[largest - 1]) {
    largest = r;
  }

  if (largest != i) {
    std::swap(A[i - 1], A[largest - 1]);
    maxHeapify(A, largest);
  }
}

void buildMaxHeap(std::vector<int> &A) {
  int H = A.size();

  for (int i = H / 2; i >= 1; i--) {
    maxHeapify(A, i);
  }
}

int main() {
  int H;
  std::cin >> H;
  std::vector<int> A(H);

  for (int i = 0; i < H; i++) {
    std::cin >> A[i];
  }

  buildMaxHeap(A);

  for (int i = 0; i < H; i++) {
    std::cout << ' ' << A[i];
  }

  std::cout << std::endl;
  return 0;
}