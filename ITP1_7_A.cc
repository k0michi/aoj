#include <iostream>

int main() {
  int m, f, r;

  while (std::cin >> m >> f >> r, m != -1 || f != -1 || r != -1) {
    int total = m + f;
    char grade;

    if (m == -1 || f == -1) {
      grade = 'F';
    } else if (total >= 80) {
      grade = 'A';
    } else if (total >= 65) {
      grade = 'B';
    } else if (total >= 50) {
      grade = 'C';
    } else if (total >= 30) {
      if (r >= 50) {
        grade = 'C';
      } else {
        grade = 'D';
      }
    } else {
      grade = 'F';
    }

    std::cout << grade << std::endl;
  }

  return 0;
}