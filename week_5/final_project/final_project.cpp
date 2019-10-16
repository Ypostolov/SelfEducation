#include <exception>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

class Date {
 public:
  Date() {
    year = 0;
    month = 1;
    day = 1;
  }
  Date(const int& y, const int& m, const int& d) {
    year = y;
    month = m;
    day = d;
  }
  void PrintDate() const {
    std::cout << std::setw(4) << std::setfill('0') << year << "-";
    std::cout << std::setw(2) << std::setfill('0') << month << "-";
    std::cout << std::setw(2) << std::setfill('0') << day;
  }
  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

 private:
  int year;
  int month;
  int day;
};
bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() < rhs.GetYear())
    return true;
  else if (lhs.GetMonth() < rhs.GetMonth())
    return true;
  else if (lhs.GetDay() < rhs.GetDay())
    return true;
  else
    return false;
}
class Database {
 public:
  void AddEvent(const Date& date, const std::string& event) {
    eve[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const std::string& event) {
    if (eve.count(date)) {
      if (eve.at(date).count(event)) {
        eve[date].erase(event);
        return true;
      }
    }
    return false;
  }
  int DeleteDate(const Date& date) {
    int size = eve[date].size();
    eve.erase(date);
    return size;
  }
  void Find(const Date& date) const {
    if (eve.count(date)) {
      std::set<std::string> dateEvents = eve.at(date);
      for (const std::string& s : dateEvents)
        std::cout << s << std::endl;
    }
  }
  void Print() const {
    for (const auto& i : eve) {
      i.first.PrintDate();
      for (const auto& j : i.second)
        std::cout << " " << j;
      std::cout << std::endl;
    }
  }

 private:
  std::map<Date, std::set<std::string> > eve;
};
int DateValueFromStream(std::stringstream& stream, const std::string& s) {
  if (stream.peek() == '-') {
    int value;
    stream.ignore(1);
    stream >> value;
    return value;
  } else {
    std::stringstream errmsg;
    errmsg << "Wrong date format: " << s;
    throw std::runtime_error(errmsg.str());
  }
}
Date DateFromString(const std::string& str) {
  if (str.empty()) {
    std::stringstream errmsg;
    errmsg << "Wrong date format: " << str;
    throw std::runtime_error(errmsg.str());
  }
  std::stringstream ss(str);
  int year;
  int month;
  int day;
  ss >> year;
  month = DateValueFromStream(ss, str);
  day = DateValueFromStream(ss, str);
  if (month < 1 || month > 12) {
    std::stringstream errmsg;
    errmsg << "Month value is invalid: " << month;
    throw std::runtime_error(errmsg.str());
  }
  if (day < 1 || day > 31) {
    std::stringstream errmsg;
    errmsg << "Day value is invalid: " << day;
    throw std::runtime_error(errmsg.str());
  }
  Date date(year, month, day);
  return date;
}
int main() {
  Database db;
  std::string command;
  try {
    while (getline(std::cin, command)) {
      if (!command.empty()) {
        std::string request;
        std::stringstream stream(command);
        stream >> request;
        if (request == "Print") {
          db.Print();
        } else if (request == "Add" || request == "Del" || request == "Find") {
          Date date;
          std::string event;
          std::string dateStr;
          stream >> dateStr;
          date = DateFromString(dateStr);
          stream >> event;
          if (request == "Find") {
            db.Find(date);
          } else {
            if (request == "Add") {
              if (event.empty()) {
                std::stringstream errmsg;
                errmsg << "Wrong date format: " << dateStr;
                throw std::runtime_error(errmsg.str());
              } else
                db.AddEvent(date, event);
            } else if (request == "Del" && !event.empty()) {
              if (db.DeleteEvent(date, event))
                std::cout << "Deleted successfully";
              else
                std::cout << "Event not found";
              std::cout << std::endl;
            } else
            {
              std::cout << "Deleted " << db.DeleteDate(date) << " events"
                        << std::endl;
            }
          }
        } else {
          std::stringstream errmsg;
          errmsg << "Unknown command: " << request;
          throw std::runtime_error(errmsg.str());
        }
      }
    }
  } catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return 0;
}
