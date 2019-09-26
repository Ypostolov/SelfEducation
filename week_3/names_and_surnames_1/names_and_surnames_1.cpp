#include <iostream>
#include <vector>
#include <map>

class Person {
 public:
  void ChangeFirstName(int year, const std::string& first_name) {
        firstName[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    lastName[year] = last_name;
  }
  std::string GetFullName(int year) {
    bool foundName = false;
    bool foundSurn = false;
    std::string name, surname;
    int limit = firstName.begin()->first;
    for (int i = year; i >= limit; --i)
    {
      if (firstName.count(i))
      {
        name = firstName[i];
        foundName = true;
        break;
      }
    }
    limit = lastName.begin()->first;
    for (int i = year; i >= limit; --i)
    {
      if (lastName.count(i))
      {
        surname = lastName[i];
        foundSurn = true;
        break;
      }
    }
    if (foundName && foundSurn)
      return name + " " + surname;
    else if (foundName)
      return name + " with unknown last name";
    else if (foundSurn)
      return surname + " with unknown first name";
    else
      return "Incognito";
    // получить имя и фамилию по состоянию на конец года year
  }
 private:
  std::map<int, std::string> firstName;
  std::map<int, std::string> lastName;
  // приватные поля
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  return 0;
}