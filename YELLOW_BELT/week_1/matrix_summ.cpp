#include <iostream>

class Matrix {
 public:
  int num_rows_;
  int num_columns_;
  int** arr;

  Matrix() {
    num_rows_ = 3;
    num_columns_ = 5;
    arr = new int*[num_rows_];
    for (int i = 0; i < num_rows_; ++i) {
      arr[i] = new int[num_columns_];
    }
  }
  ~Matrix() {
    for (int i = 0; i < num_rows_; ++i) {
      delete arr[i];
    }
  }

  void push(int row_number_, int column_number_, int val_) {
    arr[row_number_][column_number_] = val_;
  }

  void show(int row_number_, int column_number_) {
    std::cout << arr[row_number_][column_number_] << " ";
    std::cout << std::endl;
  }
};

int main() {
  Matrix one;
  one.push(0, 0, 100);
  one.push(1, 2, 210);

  one.show(0, 0);
  one.show(1, 2);
  return 0;
}
