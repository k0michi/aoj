#include <array>
#include <iostream>

std::array<int, 8> queens;

std::array<bool, 8> rows;
std::array<bool, 8> columns;
std::array<bool, 15> diagonals;
std::array<bool, 15> antiDiagonals;

void place(int r, int c, bool exist) {
  if (exist) {
    queens[r] = c;
  }

  rows[r] = columns[c] = diagonals[r - c + 7] = antiDiagonals[r + c] = exist;
}

bool canPlace(int r, int c) {
  return !rows[r] && !columns[c] && !diagonals[r - c + 7] &&
         !antiDiagonals[r + c];
}

void printBoard() {
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      std::cout << (queens[r] == c ? 'Q' : '.');
    }

    std::cout << std::endl;
  }
}

bool solve(int r) {
  if (r == 8) {
    return true;
  }

  if (rows[r]) {
    return solve(r + 1);
  }

  for (int c = 0; c < 8; c++) {
    if (canPlace(r, c)) {
      place(r, c, true);

      if (solve(r + 1)) {
        return true;
      }

      place(r, c, false);
    }
  }

  return false;
}

int main() {
  int k;
  std::cin >> k;

  for (int i = 0; i < k; i++) {
    int r, c;
    std::cin >> r >> c;
    place(r, c, true);
  }

  solve(0);
  printBoard();
  return 0;
}