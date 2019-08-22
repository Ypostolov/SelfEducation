#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool Abs(const std::string& s1, const std::string& s2) {
  char a, b;
  for (char c : s1) {
    a = tolower(c);
  };
  for (char c1 : s2) {
    b = tolower(c1);
  };
  if (a < b) {
    return true;
  }
  return false;
}

int main() {
  int A;
  std::string b;
  std::cin >> A;
  std::vector<std::string> Strings;
  if (A >= 0 && A <= 1000) {
    for (int i = 0; i < A; ++i) {
      std::cin >> b;
      if (1 <= b.length() && b.length() < 15) {
        Strings.push_back(b);
      }
    }
    sort(begin(Strings), end(Strings), Abs);

    for (const auto& s : Strings) {
      std::cout << s << " ";
    }
  }
  return 0;
}
