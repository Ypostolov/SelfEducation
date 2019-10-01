#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix {
 public:
  int num_rows_;
  int num_columns_;
  int** arr;
  std::vector<std::vector<int> > elements_;

  Matrix() {
    num_rows_ = 3;
    num_columns_ = 5;
    arr = new int*[num_rows_];
    for (int i = 0; i < num_rows_; i++) {
      arr[i] = new int[num_columns_];
    }
  }

  Matrix(int num_rows, int num_columns) {}

  int At(int row, int column) const {
    return elements_.at(row).at(column);
  }

  int& At(int row, int column) {
    return elements_.at(row).at(column);
  }

  int GetNumRows() const {
    return num_rows_;
  }

  int GetNumColumns() const {
    return num_columns_;
  }

  void push(int row_number_, int column_number_, int val_) {
    arr[row_number_][column_number_] = val_;
  }
};

bool operator==(const Matrix& one, const Matrix& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    return false;
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    return false;
  }

  for (int row = 0; row < one.GetNumRows(); ++row) {
    for (int column = 0; column < one.GetNumColumns(); ++column) {
      if (one.At(row, column) != two.At(row, column)) {
        return false;
      }
    }
  }

  return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
  if (one.GetNumRows() != two.GetNumRows()) {
    throw std::invalid_argument("Mismatched number of rows");
  }

  if (one.GetNumColumns() != two.GetNumColumns()) {
    throw std::invalid_argument("Mismatched number of columns");
  }

  Matrix result(one.GetNumRows(), one.GetNumColumns());
  for (int row = 0; row < result.GetNumRows(); ++row) {
    for (int column = 0; column < result.GetNumColumns(); ++column) {
      result.At(row, column) = one.At(row, column) + two.At(row, column);
    }
  }

  return result;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
  out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
  for (int row = 0; row < matrix.GetNumRows(); ++row) {
    for (int column = 0; column < matrix.GetNumColumns(); ++column) {
      if (column > 0) {
        out << " ";
      }
      out << matrix.At(row, column);
    }
    out << std::endl;
  }

  return out;
}

int main() {
  Matrix one;
  Matrix two;
  one.push(0, 0, 100);
  one.push(1, 2, 200);

  std::cout << one + two << std::endl;
  return 0;
}
