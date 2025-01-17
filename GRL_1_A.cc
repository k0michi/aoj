#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using llong = long long;
using ullong = unsigned long long;

using namespace std::literals;

struct Edge {
  llong to;
  llong weight;
};

using AdjacencyList = std::vector<std::vector<Edge>>;
template <class T, class Container = std::vector<T>,
          class Compare = std::greater<typename Container::value_type>>
using ReversePriorityQueue = std::priority_queue<T, Container, Compare>;

constexpr llong kInf = std::numeric_limits<llong>::max() / 2;

std::vector<llong> dijkstra(const AdjacencyList &graph, llong start) {
  ReversePriorityQueue<std::pair<llong, llong>> queue;
  std::vector<llong> distances(graph.size(), kInf);
  queue.emplace(distances[start] = 0, start);

  while (!queue.empty()) {
    auto [dist, vert] = queue.top();
    queue.pop();

    if (distances[vert] < dist) {
      continue;
    }

    for (auto &&edge : graph[vert]) {
      if (distances[edge.to] > distances[vert] + edge.weight) {
        distances[edge.to] = distances[vert] + edge.weight;
        queue.emplace(distances[edge.to], edge.to);
      }
    }
  }

  return distances;
}

void answer() {
  llong V, E, r;
  std::cin >> V >> E >> r;
  AdjacencyList graph(V);

  for (llong i = 0; i < E; i++) {
    llong s_i, t_i, d_i;
    std::cin >> s_i >> t_i >> d_i;
    graph[s_i].push_back({t_i, d_i});
  }

  auto result = dijkstra(graph, r);

  for (llong i = 0; i < V; i++) {
    if (result[i] == kInf) {
      std::cout << "INF" << '\n';
    } else {
      std::cout << result[i] << '\n';
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  answer();
  return 0;
}