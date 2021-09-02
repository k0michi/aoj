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

  void rotate() {
    std::swap(faces[1], faces[3]);
    std::swap(faces[3], faces[4]);
    std::swap(faces[4], faces[2]);
  }
};

int main() {
  Dice dice;

  for (int i = 1; i <= 6; i++) {
    std::cin >> dice.face(i);
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int top, front;
    std::cin >> top >> front;

    for (int j = 0; j < 3; j++) {
      if (dice.face(1) != top) {
        dice.roll('N');
      }
    }

    for (int j = 0; j < 3; j++) {
      if (dice.face(1) != top) {
        dice.roll('E');
      }
    }

    for (int j = 0; j < 3; j++) {
      if (dice.face(2) != front) {
        dice.rotate();
      }
    }

    std::cout << dice.face(3) << std::endl;
  }

  return 0;
}