#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void MakeWorry(std::vector<std::string> &queue, int place) {
  queue[place] = "WORRY";
}

int WorryCount(const std::vector<std::string> &queue) {
  return count(queue.begin(), queue.end(), "WORRY");
}

void MakeQuiet(std::vector<std::string> &queue, int place) {
  queue[place] = "QUIET";
}

void AddQuiet(std::vector<std::string> &queue, int numberOfPeople) {
  for (int i = 0; i < numberOfPeople; i++) {
    queue.push_back("QUIET");
  }
}

void RemoveQuiet(std::vector<std::string> &queue, int numberOfPeople) {
  for (int i = 0; i < -numberOfPeople; i++) {
    queue.pop_back();
  }
}

int main() {

  int Q = 0; // quantity of operations
  std::vector<std::string> queue(0);
  int quantity_of_people = 0;
  std::string command;

  std::cin >> Q;

  while (Q) {

    std::cin >> command;

    if (command == "WORRY_COUNT") {
      std::cout << WorryCount(queue) << std::endl;
    } else {
      std::cin >> quantity_of_people;

      if (command == "WORRY") {
        MakeWorry(queue, quantity_of_people);
      } else if (command == "QUIET") {
        MakeQuiet(queue, quantity_of_people);
      } else if (command == "COME" && quantity_of_people > 0) {
        AddQuiet(queue, quantity_of_people);
      } else if (command == "COME" && quantity_of_people < 0) {
        RemoveQuiet(queue, quantity_of_people);
      }
    }
    --Q;
  }

  return 0;
}