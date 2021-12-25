#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

struct Flood {
  int area;
  int endX;
  int y;
};

std::vector<Flood> calculateFloods(const std::string &terrain) {
  std::stack<int> slopes;
  std::vector<Flood> floods;
  int y = 0;

  for (int x = 0; x < terrain.size(); x++) {
    if (terrain[x] == '\\') {
      slopes.push(x);
      y--;
    }

    if (terrain[x] == '/') {
      y++;

      if (slopes.size() > 0) {
        int endX = x;
        int beginX = slopes.top();
        slopes.pop();
        int area = endX - beginX;

        while (floods.size() > 0 && floods.back().endX > beginX &&
               floods.back().y < y) {
          area += floods.back().area;
          floods.pop_back();
        }

        floods.push_back({area, endX, y});
      }
    }
  }

  return floods;
}

int main() {
  std::string terrain;
  std::cin >> terrain;
  std::vector<Flood> floods = calculateFloods(terrain);

  int areaSum =
      std::accumulate(floods.begin(), floods.end(), 0,
                      [](int s, const Flood &f) { return s + f.area; });

  std::cout << areaSum << std::endl;
  std::cout << floods.size();

  for (int i = 0; i < floods.size(); i++) {
    std::cout << ' ' << floods[i].area;
  }

  std::cout << std::endl;
  return 0;
}