#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SortedStrings {
 public:
  void AddString(const std::string& s) {
    data.push_back(s);
  }
  std::vector<std::string> GetSortedStrings() {
    sort(begin(data), end(data));
    return data;
  }

 private:
  std::vector<std::string> data;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const std::string& s : strings.GetSortedStrings()) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}

