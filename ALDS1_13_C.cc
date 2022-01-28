#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

template <class T, class Container = std::vector<T>,
          class Compare = std::greater<typename Container::value_type>>
using reverse_priority_queue = std::priority_queue<T, Container, Compare>;

std::array<std::array<int, 2>, 4> deltas = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
std::array<std::array<int, 16>, 16> distTable;

struct State {
  std::array<int, 16> slots;
  int stepCount = 0;
  int emptySlot;
  int heuristic;

  int estimate() const { return stepCount + heuristic; }

  bool operator>(const State &s) const { return estimate() > s.estimate(); }
};

int destSlot(int s) { return s == 0 ? 15 : s - 1; }

int manhattanDist(int s1, int s2) { return distTable[s1][s2]; }

int calculateHeuristic(const State &state) {
  int heuristic = 0;

  for (int i = 0; i < 16; i++) {
    if (state.slots[i] != 0) {
      heuristic += manhattanDist(i, destSlot(state.slots[i]));
    }
  }

  return heuristic;
}

State solve(State &initialState) {
  initialState.heuristic = calculateHeuristic(initialState);
  reverse_priority_queue<State> states;
  states.push(initialState);
  std::set<std::array<int, 16>> stateSet;

  while (states.top().heuristic != 0) {
    State state = states.top();
    states.pop();
    stateSet.insert(state.slots);

    for (int i = 0; i < 4; i++) {
      State newState = state;
      int s1 = newState.emptySlot;
      int x1 = s1 % 4;
      int y1 = s1 / 4;
      int x2 = x1 + deltas[i][0];
      int y2 = y1 + deltas[i][1];

      if (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4) {
        int s2 = y2 * 4 + x2;
        newState.heuristic -= manhattanDist(s2, destSlot(newState.slots[s2]));
        newState.heuristic += manhattanDist(s1, destSlot(newState.slots[s2]));
        std::swap(newState.slots[s1], newState.slots[s2]);
        newState.emptySlot = s2;
        newState.stepCount++;

        if (stateSet.find(newState.slots) == stateSet.end()) {
          states.push(newState);
        }
      }
    }
  }

  return states.top();
}

int main() {
  State initialState;

  for (int i = 0; i < 16; i++) {
    std::cin >> initialState.slots[i];

    if (initialState.slots[i] == 0) {
      initialState.emptySlot = i;
    }
  }

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      int x1 = i % 4;
      int y1 = i / 4;
      int x2 = j % 4;
      int y2 = j / 4;
      distTable[i][j] = std::abs(x1 - x2) + std::abs(y1 - y2);
    }
  }

  int stepCount = solve(initialState).stepCount;
  std::cout << stepCount << std::endl;
  return 0;
}