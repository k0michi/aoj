#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
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
#include <type_traits>
#include <utility>
#include <vector>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = std::make_signed<size_t>::type;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;

// b is in a?
bool include(const std::vector<i32> &a, const std::vector<i32> &b) {
  auto ai = a.begin();
  auto bi = b.begin();

  while (bi != b.end()) {
    if (ai == a.end() || *ai > *bi) {
      return false;
    } else if (*ai < *bi) {
      ai++;
    } else { // *ai == *bi
      ai++;
      bi++;
    }
  }

  return true;
}

int main() {
  i32 n;
  std::cin >> n;
  std::vector<i32> a(n);

  for (auto &&ai : a) {
    std::cin >> ai;
  }

  i32 m;
  std::cin >> m;
  std::vector<i32> b(m);

  for (auto &&bi : b) {
    std::cin >> bi;
  }

  std::cout << include(a, b) << std::endl;

  return 0;
}