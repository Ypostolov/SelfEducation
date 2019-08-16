#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  std::set<std::set<std::string> > listSinops;
  std::map<std::string, int> listWord;
  std::string action;
  int count_iteration;
  std::cin >> count_iteration;
  for (int i = 0; i < count_iteration; i++) {
    std::cin >> action;
    if (action == "ADD") {
      std::string wordOne, wordTwo;
      std::cin >> wordOne >> wordTwo;
      listSinops.insert({wordOne, wordTwo});
      listWord[wordOne]++;
      listWord[wordTwo]++;
      continue;
    }

    if (action == "COUNT") {
      std::string word;
      std::cin >> word;
      std::cout << listWord[word] << std::endl;
      continue;
    }

    if (action == "CHECK") {
      std::string wordOne, wordTwo;
      std::cin >> wordOne >> wordTwo;

      std::set<std::string> sinops = {wordOne, wordTwo};
      if (listSinops.count(sinops) == 1) {
        std::cout << "YES" << std::endl;
      } else {
        std::cout << "NO" << std::endl;
      }
      continue;
    }
  }

  return 0;
}