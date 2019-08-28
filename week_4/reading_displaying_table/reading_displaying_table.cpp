#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::ifstream input("input.txt");
  int n, m;
  input >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      input >> x;
      input.ignore(1);
      std::cout << std::setw(10) << x;
      if (j != m - 1) {
        std::cout << " ";
      }
    }
    if (i != n - 1) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}
