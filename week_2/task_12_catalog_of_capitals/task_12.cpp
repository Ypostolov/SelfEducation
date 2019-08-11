#include <iostream>
#include <map>
#include <string>

int main() {

  std::map<std::string, std::string> country_capital;

  int n;
  std::cin >> n;

  while (n > 0) {

    std::string command;
    std::cin >> command;

    if (command == "CHANGE_CAPITAL") {

      std::string country, new_capital;
      std::cin >> country >> new_capital;

      if (country_capital.count(country) == 0) {
        std::cout << "Introduce new country " << country << " with capital "
                  << new_capital << std::endl;
        country_capital[country] = new_capital;

      } else if (country_capital[country] == new_capital) {
        std::cout << "Country " << country << " hasn't changed its capital"
                  << std::endl;

      } else if (country_capital[country] != new_capital) {
        std::cout << "Country " << country << " has changed its capital from "
                  << country_capital[country] << " to " << new_capital
                  << std::endl;
        country_capital[country] = new_capital;
      }

    } else if (command == "RENAME") {

      std::string old_country_name, new_country_name;
      std::cin >> old_country_name >> new_country_name;

      if (new_country_name == old_country_name ||
          country_capital.count(old_country_name) == 0 ||
          country_capital.count(new_country_name) != 0) {
        std::cout << "Incorrect rename, skip" << std::endl;
        country_capital.erase(old_country_name);

      } else if (country_capital.count(old_country_name) != 0) {
        std::cout << "Country " << old_country_name << " with capital "
                  << country_capital[old_country_name]
                  << " has been renamed to " << new_country_name << std::endl;
        country_capital[new_country_name] = country_capital[old_country_name];
        country_capital.erase(old_country_name);
      }

    } else if (command == "ABOUT") {

      std::string country;
      std::cin >> country;

      if (country_capital.count(country) == 0) {
        std::cout << "Country " << country << " doesn't exist" << std::endl;
        country_capital.erase(country);

      } else {
        std::cout << "Country " << country << " has capital "
                  << country_capital[country] << std::endl;
      }

    } else if (command == "DUMP") {

      if (country_capital.size() == 0) {
        std::cout << "There are no countries in the world" << std::endl;

      } else {
        for (auto &item : country_capital) {
          std::cout << item.first << "/" << item.second << " ";
        }
        std::cout << std::endl;
      }
    }

    --n;
  }

  return 0;
}