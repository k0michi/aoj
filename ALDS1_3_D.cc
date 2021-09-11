#include <iostream>
#include <string>
#include <tuple>
#include <vector>

std::string terrain;
std::vector<int> floods;

std::tuple<int, int> calculateFlood(int slopeBegin) {
  if (terrain[slopeBegin] != '\\') {
    return {0, -1};
  }

  int depth = 1;
  int flood = 1;
  int slopeEnd = -1;

  for (int i = slopeBegin + 1; i < terrain.size(); i++) {
    if (terrain[i] == '\\') {
      depth++;
    } else if (terrain[i] == '/') {
      depth--;
    }

    if (depth == 0 && terrain[i] == '/') {
      flood++;
      slopeEnd = i;
      break;
    }

    flood += 2;
  }

  if (slopeEnd == -1) {
    return {0, -1};
  }

  flood /= 2;

  for (int i = slopeBegin + 1; i <= slopeEnd; i++) {
    auto [floodLower, slopeLowerEnd] = calculateFlood(i);

    if (floodLower > 0) {
      flood += floodLower;
      i = slopeLowerEnd;
    }
  }

  return {flood, slopeEnd};
}

int main() {
  std::cin >> terrain;
  int floodTotal = 0;

  for (int i = 0; i < terrain.size(); i++) {
    auto [flood, slopeEnd] = calculateFlood(i);

    if (flood > 0) {
      floodTotal += flood;
      floods.push_back(flood);
      i = slopeEnd;
    }
  }

  std::cout << floodTotal << std::endl;
  std::cout << floods.size();

  for (int i = 0; i < floods.size(); i++) {
    std::cout << ' ' << floods[i];
  }

  std::cout << std::endl;
  return 0;
}