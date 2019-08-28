#include <iostream>
#include <string>
#include <vector>

struct Student {
  std::string Name;
  std::string surname;
  int Day;
  int Month;
  int Year;
};

int main() {
  int n, m;
  std::string name;
  std::string surname;
  int day;
  int month;
  int year;
  std::vector<Student> vec;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> name >> surname >> day >> month >> year;
    vec.push_back({name, surname, day, month, year});
  }
  std::cin >> m;
  std::string command;
  int key;
  for (int j = 0; j < m; ++j) {
    std::cin >> command >> key;
    if (vec.size() < key || key <= 0) {
      std::cout << "bad request" << std::endl;
    } else if (command == "name") {
      std::cout << vec[key - 1].Name << " " << vec[key - 1].surname
                << std::endl;
    } else if (command == "date") {
      std::cout << vec[key - 1].Day << "." << vec[key - 1].Month << "."
                << vec[key - 1].Year << std::endl;
    }
    std::cout << "bad request" << std::endl;
  }
  return 0;
}