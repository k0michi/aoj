#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

int merge(std::vector<int> &A, int left, int mid, int right) {
  std::vector<int> L(std::next(A.begin(), left), std::next(A.begin(), mid));
  std::vector<int> R(std::next(A.begin(), mid), std::next(A.begin(), right));
  L.push_back(std::numeric_limits<int>::max());
  R.push_back(std::numeric_limits<int>::max());

  int i = 0;
  int j = 0;
  int count = 0;

  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }

    count++;
  }

  return count;
}

int mergeSort(std::vector<int> &A, int left, int right) {
  int count = 0;

  if (left + 1 < right) {
    int mid = (left + right) / 2;
    count += mergeSort(A, left, mid);
    count += mergeSort(A, mid, right);
    count += merge(A, left, mid, right);
  }

  return count;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> S(n);

  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }

  int count = mergeSort(S, 0, n);

  for (int i = 0; i < n; i++) {
    std::cout << S[i];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  std::cout << count << std::endl;
  return 0;
}
