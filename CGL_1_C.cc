#include <cmath>
#include <iostream>

constexpr double PI = 3.141592653589793;

struct Vector2 {
  double x;
  double y;

  double lengthSquared() { return x * x + y * y; }

  bool operator==(const Vector2 &b) const { return x == b.x && y == b.y; }
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

double normalizeAngle(double a) { return std::atan2(std::sin(a), std::cos(a)); }

int main() {
  Vector2 p0;
  Vector2 p1;
  std::cin >> p0.x >> p0.y >> p1.x >> p1.y;

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    Vector2 p2;
    std::cin >> p2.x >> p2.y;

    Vector2 P1 = p1 - p0;
    Vector2 P2 = p2 - p0;
    double a1 = std::atan2(P1.y, P1.x);
    double a2 = std::atan2(P2.y, P2.x);
    double a = normalizeAngle(a2 - a1);

    if (p2 == p0 || a == 0) {
      if (P2.lengthSquared() <= P1.lengthSquared()) {
        std::cout << "ON_SEGMENT" << std::endl;
      } else {
        std::cout << "ONLINE_FRONT" << std::endl;
      }
    } else if (a == PI || a == -PI) {
      std::cout << "ONLINE_BACK" << std::endl;
    } else if (a > 0) {
      std::cout << "COUNTER_CLOCKWISE" << std::endl;
    } else if (a < 0) {
      std::cout << "CLOCKWISE" << std::endl;
    }
  }

  return 0;
}