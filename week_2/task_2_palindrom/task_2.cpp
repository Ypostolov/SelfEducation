#include <iostream>
using namespace std;

bool IsPalindrom(string s) {
    
  if (s.empty()) {
  };
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
}

int main() {

  string a;
  std::getline(std::cin, a);
  std::cout << IsPalindrom(a);
  return 0;
}