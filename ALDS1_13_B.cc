#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

std::array<std::array<int, 2>, 4> deltas = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

struct State {
  std::array<int, 9> slots;
  std::vector<int> steps;
  int emptySlot;
};

bool isComplete(const State &state) {
  for (int i = 0; i < 8; i++) {
    if (state.slots[i] != i + 1) {
      return false;
    }
  }

  return true;
}

State solve(const State &initialState) {
  std::queue<State> states;
  states.push(initialState);
  std::map<std::array<int, 9>, bool> stateMap;

  while (!isComplete(states.front())) {
    State state = states.front();
    states.pop();
    stateMap[state.slots] = true;

    for (int i = 0; i < 4; i++) {
      State newState = state;
      int s1 = newState.emptySlot;
      int x1 = s1 % 3;
      int y1 = s1 / 3;
      int x2 = x1 + deltas[i][0];
      int y2 = y1 + deltas[i][1];

      if (x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3) {
        int s2 = y2 * 3 + x2;
        std::swap(newState.slots[s1], newState.slots[s2]);
        newState.emptySlot = s2;
        newState.steps.push_back(i);

        if (!stateMap[newState.slots]) {
          states.push(newState);
        }
      }
    }
  }

  return states.front();
}

int main() {
  State initialState;

  for (int i = 0; i < 9; i++) {
    std::cin >> initialState.slots[i];

    if (initialState.slots[i] == 0) {
      initialState.emptySlot = i;
    }
  }

  int stepCount = solve(initialState).steps.size();
  std::cout << stepCount << std::endl;
  return 0;
}