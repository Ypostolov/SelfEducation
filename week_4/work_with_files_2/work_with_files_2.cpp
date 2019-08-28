#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream input("input.txt");
  std::string line;
  std::ofstream output("output.txt", std::ios::app);
  while (getline(input, line)) {
    output << line << "\n";
  }
  return 0;
}
