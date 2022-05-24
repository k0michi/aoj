#include <cmath>
#include <iostream>

constexpr double EPSILON = 1e-8;

struct Vector2 {
  double x;
  double y;
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

Vector2 readVector2() {
  Vector2 v;
  std::cin >> v.x >> v.y;
  return v;
}

double getAngle(const Vector2 &v) { return std::atan(v.y / v.x); }

bool isPerpendicular(const Vector2 &v) { return v.x == 0; }

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    Vector2 vA = readVector2();
    Vector2 vB = readVector2();
    Vector2 vC = readVector2();
    Vector2 vD = readVector2();
    Vector2 vAB = vB - vA;
    Vector2 vCD = vD - vC;

    bool result = false;

    if (isPerpendicular(vAB) && isPerpendicular(vCD)) {
      result = true;
    } else {
      double a1 = getAngle(vB - vA);
      double a2 = getAngle(vD - vC);
      result = std::abs(a1 - a2) < EPSILON;
    }

    std::cout << (result ? "YES" : "NO") << std::endl;
  }

  return 0;
}