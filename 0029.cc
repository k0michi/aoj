#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> freqs;
  std::string word;
  int freqMax = -1;
  std::string mostFreqWord;
  std::string longestWord;

  while (std::cin >> word, !std::cin.eof()) {
    int freq = ++freqs[word];

    if (freq > freqMax) {
      freqMax = freq;
      mostFreqWord = word;
    }

    if (word.length() > longestWord.length()) {
      longestWord = word;
    }
  }

  std::cout << mostFreqWord << ' ' << longestWord << std::endl;
  return 0;
}