#include <array>
#include <iostream>

std::array<int, 12> daysInMonth = {31, 29, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
std::array<const char *, 7> dayStrings = {"Monday",   "Tuesday", "Wednesday",
                                          "Thursday", "Friday",  "Saturday",
                                          "Sunday"};

int main() {
  int m, d;

  while (std::cin >> m >> d, m != 0) {
    int days = 0;

    for (int i = 0; i < m - 1; i++) {
      days += daysInMonth[i];
    }

    days += d;
    int day = (2 + days) % 7;
    std::cout << dayStrings[day] << std::endl;
  }
}