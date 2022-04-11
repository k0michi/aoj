#include <algorithm>
#include <array>
#include <iostream>

int main() {
  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::array<int, 3> s;
    std::cin >> s[0] >> s[1] >> s[2];
    std::sort(s.begin(), s.end());

    bool isRight = s[0] * s[0] + s[1] * s[1] == s[2] * s[2];
    std::cout << (isRight ? "YES" : "NO") << std::endl;
  }

  return 0;
}