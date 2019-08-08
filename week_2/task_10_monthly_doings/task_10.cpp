
#include <iostream>
#include <string>
#include <vector>

int number_of_elements = 31;
int month_days_amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

std::vector<std::vector<std::string>> work(number_of_elements);

void ADD(int days, std::string new_work) {
  if ((days >= 0) && (days <= 30)) {
    work[days].push_back(new_work);
  }
}

void DUMP(int day) {
  std::vector<std::string> temp;
  if ((day >= 0) && (day <= 30)) {
    temp = work[day];
    std::cout << work[day].size() << " ";
    for (auto i : temp) {
      std::cout << i << " ";
    }
  }
  temp.clear();
  std::cout << std::endl;
}

int current_month = 0; // Starts from 0

void NEXT() {
  std::vector<std::string> temp;
  current_month += 1;
  if (current_month >= 12) {
    current_month -= 12;
  }
  int dd = month_days_amount[current_month - 1] -
           month_days_amount[current_month]; // difference between months
  int last_day = work.size() - dd;
  if (dd < 0) {
    work.resize(month_days_amount[current_month]); // next month is bigger
  } else {                                         // next month is smaller
    for (int it = 0; it < dd; ++it) {
      for (auto i : work[last_day + it]) { // for each day
        if (i.size()) {
          temp.push_back(i);
        }
        work[last_day + it].clear();
      }
    }
  }
  for (auto i : temp) {

    work[work.size() - dd - 1].push_back(i);
  }

  temp.clear();
}

int main() {

  int Q = 0;
  std::string entered_operation_name;
  std::string task;
  int date;

  std::cin >> Q;

  while (Q > 0) {

    std::cin >> entered_operation_name;

    if (entered_operation_name == "NEXT") {
      NEXT();
    }

    if (entered_operation_name == "ADD") {
      std::cin >> date;
      if ((date > month_days_amount[current_month]) || (date <= 0)) {
        std::cout << "Invalid date value" << std::endl;
        continue;
      }
      std::cin >> task;
      ADD(date - 1, task);
    }

    if (entered_operation_name == "DUMP") {
      std::cin >> date;
      DUMP(date - 1);
    }
    --Q;
  }
  return 0;
}
