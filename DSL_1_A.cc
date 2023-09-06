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

struct UnionFind {
  std::vector<i32> rank;
  std::vector<i32> parents;

  UnionFind() {}

  UnionFind(i32 size) {
    rank.resize(size, 0);
    parents.resize(size, 0);

    for (i32 i = 0; i < size; i++) {
      parents[i] = i;
      rank[i] = 0;
    }
  }

  bool same(i32 x, i32 y) { return find(x) == find(y); }

  void unite(i32 x, i32 y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return;
    }

    if (rank[x] > rank[y]) {
      parents[y] = x;
    } else {
      parents[x] = y;

      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }

  i32 find(i32 x) {
    if (x == parents[x]) {
      return x;
    }

    return find(parents[x]);
  }
};

int main() {
  i32 n, q;
  std::cin >> n >> q;

  UnionFind forest(n);

  for (i32 i = 0; i < q; i++) {
    std::string com;
    std::cin >> com;

    if (com == "0") {
      i32 x, y;
      std::cin >> x >> y;

      forest.unite(x, y);
    } else if (com == "1") {
      i32 x, y;
      std::cin >> x >> y;

      std::cout << (forest.same(x, y) ? 1 : 0) << std::endl;
    }
  }

  return 0;
}