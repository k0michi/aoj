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
  i32 n, q;
  std::cin >> n >> q;
  std::vector<std::list<i32>> lists(n);

  for (i32 i = 0; i < q; i++) {
    i32 op;
    std::cin >> op;

    if (op == 0) {
      i32 t;
      std::cin >> t;
      auto &lt = lists[t];
      i32 x;
      std::cin >> x;
      lt.push_back(x);
    } else if (op == 1) {
      i32 t;
      std::cin >> t;
      auto &lt = lists[t];
      auto it = lt.begin();

      while (it != lt.end()) {
        if (it != lt.begin()) {
          std::cout << ' ';
        }

        std::cout << *it;
        it++;
      }

      std::cout << std::endl;
    } else if (op == 2) {
      i32 s, t;
      std::cin >> s >> t;
      lists[t].splice(lists[t].end(), lists[s]);
    }
  }

  return 0;
}