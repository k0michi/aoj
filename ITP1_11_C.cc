#include <array>
#include <iostream>

struct Dice {
  std::array<int, 6> faces;

  int &face(int label) { return faces[label - 1]; }

  const int &face(int label) const { return faces[label - 1]; }

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

  bool operator==(const Dice &d) const { return faces == d.faces; }
};

bool isIdentical(const Dice &a, Dice b) {
  for (int i = 0; i < 4; i++) {
    if (a.face(1) == b.face(1)) {
      for (int j = 0; j < 4; j++) {
        if (a == b) {
          return true;
        }

        b.rotate();
      }
    }

    b.roll('N');
  }

  for (int i = 0; i < 4; i++) {
    if (a.face(1) == b.face(1)) {
      for (int j = 0; j < 4; j++) {
        if (a == b) {
          return true;
        }

        b.rotate();
      }
    }

    b.roll('E');
  }

  return false;
}

int main() {
  Dice dice1;
  Dice dice2;

  for (int i = 1; i <= 6; i++) {
    std::cin >> dice1.face(i);
  }

  for (int i = 1; i <= 6; i++) {
    std::cin >> dice2.face(i);
  }

  if (isIdentical(dice1, dice2)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}