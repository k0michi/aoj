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

void print(const std::vector<i32> &a) {
  for (i32 i = 0; i < a.size(); i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << a[i];
  }

  std::cout << std::endl;
}

int main() {
  i32 n;
  std::cin >> n;

  std::vector<i32> a(n);
  std::iota(a.begin(), a.end(), 1);

  do {
    print(a);
  } while (std::next_permutation(a.begin(), a.end()));

  return 0;
}