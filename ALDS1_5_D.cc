#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

long merge(std::vector<int> &A, int left, int mid, int right) {
  std::vector<int> L(std::next(A.begin(), left), std::next(A.begin(), mid));
  std::vector<int> R(std::next(A.begin(), mid), std::next(A.begin(), right));
  L.push_back(std::numeric_limits<int>::max());
  R.push_back(std::numeric_limits<int>::max());

  int i = 0;
  int j = 0;
  long inversionCount = 0;

  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
      inversionCount += (L.size() - 1) - i;
    }
  }

  return inversionCount;
}

long mergeSort(std::vector<int> &A, int left, int right) {
  long inversionCount = 0;

  if (left + 1 < right) {
    int mid = (left + right) / 2;
    inversionCount += mergeSort(A, left, mid);
    inversionCount += mergeSort(A, mid, right);
    inversionCount += merge(A, left, mid, right);
  }

  return inversionCount;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> S(n);

  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }

  long inversionCount = mergeSort(S, 0, n);
  std::cout << inversionCount << std::endl;
  return 0;
}