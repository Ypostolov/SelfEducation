#include <iostream>
#include <map>
#include <vector>

class Person {
 private:
  std::map<int, std::string> firstName;
  std::map<int, std::string> lastName;
  int birth;

 public:
  Person(std::string name, std::string surName, int year) {
    firstName[year] = name;
    lastName[year] = surName;
    birth = year;
  }

  void ChangeFirstName(int year, const std::string& first_name) {
    if (birth <= year) {
      firstName[year] = first_name;
    } else {
      return;
    }
  }
  void ChangeLastName(int year, const std::string& last_name) {
    if (birth <= year) {
      lastName[year] = last_name;
    } else {
      return;
    }
  }
  std::string GetFullName(int year) {
    bool foundName = false;
    bool foundSurn = false;
    std::string name, surname;
    int limit = firstName.begin()->first;
    for (int i = year; i >= limit; --i) {
      if (firstName.count(i)) {
        name = firstName[i];
        foundName = true;
        break;
      }
    }
    limit = lastName.begin()->first;
    for (int i = year; i >= limit; --i) {
      if (lastName.count(i)) {
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
      return "No person";
    // получить имя и фамилию по состоянию на конец года year
  }

  std::vector<std::string> FormNamesHistory(int year,
                                            std::map<int, std::string>& data) {
    std::vector<std::string> result;
    int limit = data.begin()->first;
    for (int i = year; i >= limit; --i) {
      if (data.count(i))
        result.push_back(data[i]);
    }
    return result;
  }

  std::string GetHistoryNames(const std::vector<std::string>& data)

  {
    std::string result;  // = " (";
    std::string check = data[0];
    int limit = data.size() - 1;
    for (int i = 1; i < limit; ++i) {
      if (check != data[i]) {
        result += data[i] + ", ";
        check = data[i];
      }
    }
    if (data[limit] != check)
      result += data[limit];
    if (!result.empty()) {
      return " (" + result + ")";
    }
    // result += ")";

    return result;
  }
  std::string GetFullNameWithHistory(int year) {
    std::vector<std::string> names = FormNamesHistory(year, firstName);
    std::vector<std::string> surnames = FormNamesHistory(year, lastName);
    std::string result;

    if (!names.empty() && !surnames.empty()) {
      result = names[0];
      if (names.size() > 1) {
        result += GetHistoryNames(names);
      }
      result += (" " + surnames[0]);
      if (surnames.size() > 1) {
        result += GetHistoryNames(surnames);
      }
      return result;
    } else if (!names.empty()) {
      result = names[0];
      if (names.size() > 1) {
        result += GetHistoryNames(names);
      }
      result += " with unknown last name";
    } else if (!surnames.empty()) {
      result = surnames[0];
      if (surnames.size() > 1) {
        result += GetHistoryNames(surnames);
      }
      result += " with unknown first name";
    } else
      result = "No person";
    return result;
  }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  return 0;
}
