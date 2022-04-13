#include <iomanip>
#include <iostream>

struct Vector2 {
  double x;
  double y;
};

Vector2 operator+(const Vector2 &a, const Vector2 &b) {
  return {a.x + b.x, a.y + b.y};
}

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

Vector2 operator*(double a, const Vector2 &b) { return {a * b.x, a * b.y}; }

int operator*(const Vector2 &a, const Vector2 &b) {
  return a.x * b.x + a.y * b.y;
}

Vector2 operator/(const Vector2 &a, double b) { return {a.x / b, a.y / b}; }

int main() {
  Vector2 p1;
  Vector2 p2;
  std::cin >> p1.x >> p1.y >> p2.x >> p2.y;

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    Vector2 p;
    std::cin >> p.x >> p.y;

    Vector2 x =
        p1 + ((p - p1) * (p2 - p1) * (p2 - p1)) / ((p2 - p1) * (p2 - p1));
    std::cout << std::fixed << std::setprecision(8);
    std::cout << x.x << ' ' << x.y << std::endl;
  }

  return 0;
}