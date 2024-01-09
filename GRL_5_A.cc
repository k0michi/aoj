// Preamble begin

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstring>
#include <deque>
#include <forward_list>
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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
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
using f32 = float;
using f64 = double;

// Preamble end

struct Edge {
  i32 to;
  i32 weight;
};

std::vector<std::vector<Edge>> graph;
std::vector<i32> distance;

constexpr i32 kInfty = std::numeric_limits<i32>::max();

void bfs(i32 v) {
  std::fill(distance.begin(), distance.end(), kInfty);
  std::queue<i32> q;
  q.push(v);
  distance[v] = 0;

  while (!q.empty()) {
    i32 u = q.front();
    q.pop();

    for (i32 i = 0; i < graph[u].size(); ++i) {
      Edge e = graph[u][i];

      if (distance[e.to] == kInfty) {
        distance[e.to] = distance[u] + e.weight;
        q.push(e.to);
      }
    }
  }
}

i32 treeDiameter() {
  bfs(0);

  auto maxIt = std::max_element(distance.begin(), distance.end());
  bfs(std::distance(distance.begin(), maxIt));
  return *std::max_element(distance.begin(), distance.end());
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n;
  std::cin >> n;
  graph.resize(n);
  distance.resize(n);

  for (i32 i = 0; i < n - 1; ++i) {
    i32 s, t, w;
    std::cin >> s >> t >> w;
    graph[s].push_back({t, w});
    graph[t].push_back({s, w});
  }

  std::cout << treeDiameter() << std::endl;

  return 0;
}