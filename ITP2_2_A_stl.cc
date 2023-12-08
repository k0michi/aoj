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
  std::vector<std::stack<i32>> stacks(n);

  for (i32 i = 0; i < q; i++) {
    i32 op, t;
    std::cin >> op >> t;
    auto &st = stacks[t];

    if (op == 0) {
      i32 x;
      std::cin >> x;
      st.push(x);
    } else if (op == 1) {
      if (!st.empty()) {
        std::cout << st.top() << std::endl;
      }
    } else if (op == 2) {
      if (!st.empty()) {
        st.pop();
      }
    }
  }

  return 0;
}