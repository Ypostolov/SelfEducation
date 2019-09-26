#include <iostream>
#include <map>
#include <vector>

class Person {
 private:
  std::map<int, std::string> firstName;
  std::map<int, std::string> lastName;

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
      return "Incognito";
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
      result = "Incognito";
    return result;
  }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;

  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;

  return 0;
}
