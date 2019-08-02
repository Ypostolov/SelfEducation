#include <iostream>
#include <string>
#include <vector>

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

vector<string> PalindromFilter(vector<string> words, int minLength) {
  vector<string> output;

  for (auto i : words) {
    if (i.size() >= minLength && IsPalindrom(i))
      output.push_back(i);
  }

  return output;
}

int main() {
  vector<string> vec = {"weew", "bro", "code"};
  vector<string> b;

  b = PalindromFilter(vec, 4);
  for (auto i : b) {
    cout << i << " ";
  }

  return 0;
}