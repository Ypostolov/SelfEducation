#include <algorithm>
#include <iostream>
#include <vector>

bool myfunc(const int& i, const int& j) {
  if (abs(i) < abs(j)) {
    return true;
  }
  return false;
}

int main() {
  int A;
  double b;
  std::cin >> A;
  std::vector<int> Numbers;
  if (A >= 0 && A <= 1000) {
    for (int i = 0; i < A; ++i) {
      std::cin >> b;
      if (-1000000 <= b && b <= 1000000) {
        Numbers.push_back(b);
      }
    }
    sort(begin(Numbers), end(Numbers), myfunc);
    for (const auto& s : Numbers) {
      std::cout << s << " ";
    }
  }
  return 0;
}
