#include <iostream>
#include <queue>
#include <string>

struct Process {
  std::string name;
  int time;
};

int main() {
  int n;
  int q;
  std::cin >> n >> q;

  std::queue<Process> processes;
  int currentTime = 0;

  for (int i = 0; i < n; i++) {
    std::string name;
    int time;
    std::cin >> name >> time;

    processes.push({name, time});
  }

  while (!processes.empty()) {
    auto process = processes.front();
    processes.pop();

    if (process.time > q) {
      process.time -= q;
      currentTime += q;
      processes.push(process);
    } else {
      currentTime += process.time;
      std::cout << process.name << ' ' << currentTime << std::endl;
    }
  }

  return 0;
}