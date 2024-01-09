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

std::vector<bool> visited;
std::vector<i32> prenum;
std::vector<i32> parent;
std::vector<i32> lowest;
i32 now = 0;

void dfs(const std::vector<std::vector<i32>> &graph, i32 prev, i32 current) {
  prenum[current] = lowest[current] = now;
  ++now;

  visited[current] = true;

  for (i32 i = 0; i < graph[current].size(); ++i) {
    i32 next = graph[current][i];

    if (!visited[next]) {
      parent[next] = current;

      dfs(graph, current, next);

      lowest[current] = std::min(lowest[current], lowest[next]);
    } else if (next != prev) {
      lowest[current] = std::min(lowest[current], prenum[next]);
    }
  }
}

std::set<i32> articulationPoints(const std::vector<std::vector<i32>> &graph) {
  std::fill(visited.begin(), visited.end(), false);

  now = 1;

  dfs(graph, -1, 0);

  std::set<i32> result;

  i32 rootChildren = 0;

  for (i32 i = 1; i < graph.size(); ++i) {
    i32 p = parent[i];

    if (p == 0) {
      // i's parent is the root
      ++rootChildren;
    } else if (prenum[p] <= lowest[i]) {
      result.insert(p);
    }
  }

  if (rootChildren >= 2) {
    result.insert(0);
  }

  return result;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 vNum, eNum;
  std::cin >> vNum >> eNum;

  std::vector<std::vector<i32>> graph(vNum);
  visited.resize(vNum);
  prenum.resize(vNum);
  parent.resize(vNum);
  lowest.resize(vNum);

  for (i32 i = 0; i < eNum; ++i) {
    i32 s, t;
    std::cin >> s >> t;
    graph[s].push_back(t);
    graph[t].push_back(s);
  }

  auto result = articulationPoints(graph);

  for (auto it = result.begin(); it != result.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}