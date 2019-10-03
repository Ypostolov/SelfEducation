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

  Matrix(int row_number_, int column_number_) {
    num_rows_ = row_number_;
    num_columns_ = column_number_;
    arr = new int*[num_rows_];
    for (int i = 0; i < num_rows_; ++i) {
      arr[i] = new int[num_columns_];
    }
  }
  ~Matrix() {
    for (int i = 0; i < num_rows_; ++i) {
      delete[] arr[i];
    }
    delete[] arr;
  }

  void push(int row_number_, int column_number_, int val_) {
    arr[row_number_][column_number_] = val_;
  }

  int GetNumRows() const {
    return num_rows_;
  }

  int GetNumColumns() const {
    return num_columns_;
  }

  int At(int row_number_, int column_number_) const {
    return arr[row_number_][column_number_];
  }

  int& At(int row_number_, int column_number_) {
    return arr[row_number_][column_number_];
  }
};

void fill(Matrix& a) {
  for (int i = 0; i < a.GetNumRows(); ++i) {
    for (int j = 0; j < a.GetNumColumns(); ++j) {
      a.push(i, j, rand() % 20);
    }
  }
  std::cout << std::endl;
}

void show(const Matrix& a) {
  std::cout << a.GetNumRows() << "  " << a.GetNumColumns();
  std::cout << std::endl;
  for (int i = 0; i < a.GetNumRows(); ++i) {
    for (int j = 0; j < a.GetNumColumns(); ++j) {
      std::cout << a.At(i, j) << "  ";
    }
    std::cout << std::endl;
  }
}

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

int main() {
  Matrix one;
  fill(one);
  show(one);

  Matrix two;
  fill(two);
  show(two);

  const Matrix rezult = one + two;

  std::cout << std::endl;
  show(rezult);

  return 0;
}
