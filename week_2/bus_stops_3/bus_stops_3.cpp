#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  int Q;
  std::cin >> Q;
  std::string stop;
  int stops_count;
  int k = 1;
  std::set<std::string> stops;
  std::map<std::set<std::string>, int> route;

  for (int it = 0; it < Q; ++it) {
    std::cin >> stops_count;

    for (int i = 0; i < stops_count; ++i) {
      std::cin >> stop;
      stops.insert(stop);
    }

    if (route.count(stops) != 0) {
      std::cout << "Already exists for " << route[stops] << std::endl;
    } else {
      route[stops] = k;
      std::cout << "New bus " << route[stops] << std::endl;
      ++k;
    }
    stops.clear();
  }

  return 0;
}