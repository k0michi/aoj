#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
  std::string t;
  std::string p;
  std::cin >> t >> p;
  int tSize = t.size();
  int pSize = p.size();

  for (int i = 0; i < tSize - pSize + 1; i++) {
    if (t.substr(i, pSize) == p) {
      std::cout << i << std::endl;
    }
  }

  return 0;
}