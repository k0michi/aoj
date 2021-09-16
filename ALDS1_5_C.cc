#include <cmath>
#include <iomanip>
#include <iostream>

constexpr double PI = 3.141592653589793;

struct Vector2 {
  double x;
  double y;
};

void printVector(const Vector2 &p) {
  std::cout << p.x << ' ' << p.y << std::endl;
}

void koch(int n, const Vector2 &p1, const Vector2 &p2) {
  if (n == 0) {
    return;
  }

  Vector2 s{(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
  Vector2 t{(p1.x + 2 * p2.x) / 3, (p1.y + 2 * p2.y) / 3};
  Vector2 u{
      (t.x - s.x) * std::cos(PI / 3) - (t.y - s.y) * std::sin(PI / 3) + s.x,
      (t.x - s.x) * std::sin(PI / 3) + (t.y - s.y) * std::cos(PI / 3) + s.y};

  koch(n - 1, p1, s);
  printVector(s);
  koch(n - 1, s, u);
  printVector(u);
  koch(n - 1, u, t);
  printVector(t);
  koch(n - 1, t, p2);
}

int main() {
  int n;
  std::cin >> n;

  std::cout << std::fixed << std::setprecision(4);
  printVector({0, 0});
  koch(n, {0, 0}, {100, 0});
  printVector({100, 0});

  return 0;
}