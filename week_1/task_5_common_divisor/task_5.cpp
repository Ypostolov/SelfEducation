#include <iostream>

unsigned int gcd(unsigned int a, unsigned int b) {
  while (a != b) {
    if (a > b) {
      unsigned int tmp = a;
      a = b;
      b = tmp;
    }
    b = b - a;
  }
  return a;
}

int main() {
  unsigned int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b);
  return 0;
}