#include <iostream>
#include <string>

int main() {
  std::string string_1, string_2, string_3, min_string;
  std::cin >> string_1 >> string_2 >> string_3;

  if (string_1 < string_2 && string_1 < string_3) {
    min_string = string_1;
  } else if (string_2 < string_1 && string_2 < string_3) {
    min_string = string_2;
  } else {
    min_string = string_3;
  }

  std::cout << min_string;
  return 0;
}
