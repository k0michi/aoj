#include <array>
#include <iostream>

struct Dice {
  std::array<int, 6> faces;

  int &face(int label) { return faces[label - 1]; }

  void roll(char direction) {
    if (direction == 'E') {
      std::swap(faces[0], faces[3]);
      std::swap(faces[3], faces[5]);
      std::swap(faces[5], faces[2]);
    } else if (direction == 'N') {
      std::swap(faces[0], faces[1]);
      std::swap(faces[1], faces[5]);
      std::swap(faces[5], faces[4]);
    } else if (direction == 'S') {
      std::swap(faces[0], faces[4]);
      std::swap(faces[4], faces[5]);
      std::swap(faces[5], faces[1]);
    } else if (direction == 'W') {
      std::swap(faces[0], faces[2]);
      std::swap(faces[2], faces[5]);
      std::swap(faces[5], faces[3]);
    }
  }
};

int main() {
  Dice dice;

  for (int i = 1; i <= 6; i++) {
    std::cin >> dice.face(i);
  }

  std::string commands;
  std::cin >> commands;

  for (char command : commands) {
    dice.roll(command);
  }

  std::cout << dice.face(1) << std::endl;
  return 0;
}