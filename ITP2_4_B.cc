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

int main() {
  i32 n;
  std::cin >> n;
  std::vector<i32> a(n);

  for (i32 i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  i32 q;
  std::cin >> q;

  std::vector<i32> aTemp(n);

  for (i32 i = 0; i < q; i++) {
    i32 b, m, e;
    std::cin >> b >> m >> e;

    std::copy(a.begin(), a.end(), aTemp.begin());

    for (i32 j = 0; j < e - b; j++) {
      a[b + (j + (e - m)) % (e - b)] = aTemp[b + j];
    }
  }

  for (auto it = a.begin(); it != a.end(); it++) {
    if (it != a.begin()) {
      std::cout << ' ';
    }

    std::cout << *it;
  }

  std::cout << std::endl;

  return 0;
}