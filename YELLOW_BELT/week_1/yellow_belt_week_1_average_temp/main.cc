#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& print_vector) {
  for (auto i : print_vector) {
    std::cout << i << " ";
  }
}

int main() {
  uint days_amount;
  std::vector<double> tmprtr_vals;
  double summ = 0;

  std::cin >> days_amount;
  for (size_t i = 0; i < days_amount; i++) {
    int var;
    std::cin >> var;
    tmprtr_vals.push_back(var);
    summ += var;
  }

  double average;
  average = summ / days_amount;

  int amount_greater_averg = 0;
  std::vector<int> vector_of_index;
  int index_greater_averg = 0;

  for (auto i : tmprtr_vals) {
    if (i > average) {
      amount_greater_averg++;
      vector_of_index.push_back(index_greater_averg);
    }
    index_greater_averg++;
  }

  std::cout << amount_greater_averg << std::endl;
  PrintVector(vector_of_index);
  return 0;
}
