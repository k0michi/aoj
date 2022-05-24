#include <iostream>
#include <map>

int main() {
  std::map<int, int> freqs;
  int ai;
  int freqMax = -1;

  while (std::cin >> ai, !std::cin.eof()) {
    int freq = ++freqs[ai];

    if (freq > freqMax) {
      freqMax = freq;
    }
  }

  for (const auto &[value, freq] : freqs) {
    if (freq == freqMax) {
      std::cout << value << std::endl;
    }
  }

  return 0;
}