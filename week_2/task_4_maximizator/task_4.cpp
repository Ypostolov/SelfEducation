#include <iostream>

void UpdateIfGreater(const int &first, int &second) {
  if (first > second) {
    second = first;
  }
}

int main() {
  int a = 0;
  int b = -1;
  UpdateIfGreater(a, b);
  std::cout << b << std::endl;

  return 0;
}
