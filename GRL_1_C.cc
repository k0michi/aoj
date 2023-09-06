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

constexpr i64 kInfinity = std::numeric_limits<i64>::max();

void floyd(std::vector<std::vector<i64>> &graph) {
  i32 n = graph.size();

  for (i32 k = 0; k < n; k++) {
    for (i32 i = 0; i < n; i++) {
      if (graph[i][k] == kInfinity) {
        continue;
      }

      for (i32 j = 0; j < n; j++) {
        if (graph[k][j] == kInfinity) {
          continue;
        }

        graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
}

int main() {
  i32 vNum, eNum;
  std::cin >> vNum >> eNum;

  std::vector<std::vector<i64>> graph(vNum, std::vector<i64>(vNum, kInfinity));

  for (u32 i = 0; i < vNum; i++) {
    graph[i][i] = 0;
  }

  for (u32 i = 0; i < eNum; i++) {
    i32 s, t, d;
    std::cin >> s >> t >> d;
    graph[s][t] = d;
  }

  floyd(graph);

  bool negative = false;

  for (i32 i = 0; i < vNum; i++) {
    if (graph[i][i] < 0) {
      negative = true;
    }
  }

  if (negative) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (i32 i = 0; i < vNum; i++) {
      for (i32 j = 0; j < vNum; j++) {
        if (j > 0) {
          std::cout << " ";
        }

        if (graph[i][j] == kInfinity) {
          std::cout << "INF";
        } else {
          std::cout << graph[i][j];
        }
      }

      std::cout << std::endl;
    }
  }

  return 0;
}