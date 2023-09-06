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

void dfs(const std::vector<std::vector<i32>> &graph, std::vector<bool> &visited,
         i32 v, std::list<i32> &result) {
  visited[v] = true;

  for (i32 i = 0; i < graph[v].size(); i++) {
    if (!visited[graph[v][i]]) {
      dfs(graph, visited, graph[v][i], result);
    }
  }

  result.push_front(v);
}

std::list<i32> topologicalSort(const std::vector<std::vector<i32>> &graph) {
  std::vector<bool> visited(graph.size(), false);
  std::list<i32> result;

  for (i32 i = 0; i < graph.size(); i++) {
    if (!visited[i]) {
      dfs(graph, visited, i, result);
    }
  }

  return result;
}

int main() {
  i32 vNum, eNum;
  std::cin >> vNum >> eNum;

  std::vector<std::vector<i32>> graph(vNum);

  for (i32 i = 0; i < eNum; i++) {
    i32 s, t;
    std::cin >> s >> t;
    graph[s].push_back(t);
  }

  auto result = topologicalSort(graph);

  for (auto it = result.begin(); it != result.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}