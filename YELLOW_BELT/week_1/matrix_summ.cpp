#include <iostream>
template <typename T>
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

  void push(int row_number_, int column_number_, T val_) {
    arr[row_number_][column_number_] = val_;
  }

  int GetNumRows() const {
    return num_rows_;
  }

  int GetNumColumns() const {
    return num_columns_;
  }

  T At(int row_number_, int column_number_) const {
    return arr[row_number_][column_number_];
  }

  T& At(int row_number_, int column_number_) {
    return arr[row_number_][column_number_];
  }

  Matrix operator+(const Matrix& two) {
    if (this->GetNumRows() != two.GetNumRows()) {
      throw std::invalid_argument("Mismatched number of rows");
    }

    if (this->GetNumColumns() != two.GetNumColumns()) {
      throw std::invalid_argument("Mismatched number of columns");
    }

    Matrix result(this->GetNumRows(), this->GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
      for (int column = 0; column < result.GetNumColumns(); ++column) {
        result.At(row, column) = this->At(row, column) + two.At(row, column);
      }
    }

    return result;
  }

  bool operator==(const Matrix& two) {
    if (this->GetNumRows() != two.GetNumRows()) {
      return false;
    }

    if (this->GetNumColumns() != two.GetNumColumns()) {
      return false;
    }

    for (int row = 0; row < this->GetNumRows(); ++row) {
      for (int column = 0; column < this->GetNumColumns(); ++column) {
        if (this->At(row, column) != two.At(row, column)) {
          return false;
        }
      }
    }

    return true;
  }
};

template <typename T>
void fill(Matrix<T>& a) {
  for (int i = 0; i < a.GetNumRows(); ++i) {
    for (int j = 0; j < a.GetNumColumns(); ++j) {
      a.push(i, j, rand() % 20);
    }
  }
  std::cout << std::endl;
}

template <typename T>
void show(const Matrix<T>& a) {
  std::cout << a.GetNumRows() << "  " << a.GetNumColumns();
  std::cout << std::endl;
  for (int i = 0; i < a.GetNumRows(); ++i) {
    for (int j = 0; j < a.GetNumColumns(); ++j) {
      std::cout << a.At(i, j) << "  ";
    }
    std::cout << std::endl;
  }
}

int main() {
  Matrix<int> one(2, 5);
  fill(one);
  show(one);

  Matrix<int> two(2, 5);
  fill(two);
  show(two);

  const Matrix<int> rezult = one + two;

  std::cout << std::endl;
  show(rezult);

  return 0;
}
