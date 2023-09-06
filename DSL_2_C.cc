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

struct Node {
  i32 location;
  i32 parent;
  i32 left;
  i32 right;
};

struct Point {
  i32 id;
  i32 x;
  i32 y;

  Point() {}

  Point(i32 id, i32 x, i32 y) : id(id), x(x), y(y) {}

  bool operator<(const Point &other) const { return id < other.id; }
};

constexpr i32 kNil = -1;

struct KDTree {
  std::vector<Node> nodes;
  std::vector<Point> points;
  i32 nodeCount = 0;

  KDTree(std::vector<Point> points) : points(points), nodes(points.size()) {
    makeKDTree(0, points.size(), 0);
  }

  i32 makeKDTree(i32 l, i32 r, i32 depth) {
    if (!(l < r)) {
      return kNil;
    }

    i32 mid = (l + r) / 2;
    i32 index = nodeCount++;

    if (depth % 2 == 0) {
      std::sort(points.begin() + l, points.begin() + r,
                [](const Point &a, const Point &b) { return a.x < b.x; });
    } else {
      std::sort(points.begin() + l, points.begin() + r,
                [](const Point &a, const Point &b) { return a.y < b.y; });
    }

    nodes[index].location = mid;
    nodes[index].left = makeKDTree(l, mid, depth + 1);
    nodes[index].right = makeKDTree(mid + 1, r, depth + 1);

    return index;
  }

  std::vector<Point> find(i32 sx, i32 tx, i32 sy, i32 ty) {
    std::vector<Point> result;
    find(0, sx, tx, sy, ty, 0, result);
    return result;
  }

  void find(i32 v, i32 sx, i32 tx, i32 sy, i32 ty, i32 depth,
            std::vector<Point> &result) {
    i32 x = points[nodes[v].location].x;
    i32 y = points[nodes[v].location].y;

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
      result.push_back(points[nodes[v].location]);
    }

    if (depth % 2 == 0) {
      if (nodes[v].left != kNil && sx <= x) {
        find(nodes[v].left, sx, tx, sy, ty, depth + 1, result);
      }

      if (nodes[v].right != kNil && x <= tx) {
        find(nodes[v].right, sx, tx, sy, ty, depth + 1, result);
      }
    } else {
      if (nodes[v].left != kNil && sy <= y) {
        find(nodes[v].left, sx, tx, sy, ty, depth + 1, result);
      }

      if (nodes[v].right != kNil && y <= ty) {
        find(nodes[v].right, sx, tx, sy, ty, depth + 1, result);
      }
    }
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i32 n;
  std::cin >> n;
  std::vector<Point> points(n);

  for (i32 i = 0; i < n; i++) {
    i32 x, y;
    std::cin >> x >> y;
    points[i] = Point(i, x, y);
  }

  KDTree kdTree(points);

  i32 q;
  std::cin >> q;

  for (i32 i = 0; i < q; i++) {
    i32 sx, tx, sy, ty;
    std::cin >> sx >> tx >> sy >> ty;

    auto found = kdTree.find(sx, tx, sy, ty);
    std::sort(found.begin(), found.end());

    for (const Point &point : found) {
      std::cout << point.id << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}