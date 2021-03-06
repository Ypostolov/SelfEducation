#include <iostream>

class Rational {
 public:
  Rational() {
    p = 0;
    q = 1;
    divider = 1;
  }

  Rational(int numerator, int denominator) {
    if (numerator == 0) {
      p = numerator;
      q = 1;
    }

    else if (numerator < 0 && denominator < 0) {
      p = abs(numerator);
      q = abs(denominator);
    } else if (numerator < 0 || denominator < 0) {
      p = abs(numerator) * (-1);
      q = abs(denominator);
    } else {
      p = numerator;
      q = denominator;
    }
    divider = Divider();
  }

  Rational(const Rational& r) {
    p = r.p;
    q = r.q;
  }

  int Divider() {
    if (p == q) {
      return p;
    } else if (p == 0 && q != 0) {
      return q;
    } else if (p != 0 && q == 0) {
      return p;
    } else {
      int dividend_t = 0;
      int divider_t = 0;
      int reminder = 0;
      if (p > q) {
        dividend_t = p;
        divider_t = q;
      } else {
        dividend_t = q;
        divider_t = p;
      }
      reminder = dividend_t % divider_t;
      while (reminder != 0) {
        dividend_t = divider_t;
        divider_t = reminder;
        reminder = dividend_t % divider_t;
      }
      return abs(divider_t);
    }
  }

  int Numerator() const {
    return (p / divider);
  }

  int Denominator() const {
    return (q / divider);
  }

 private:
  int divider;
  int p;
  int q;
};

int test_1(int numerat, int denominat) {
  Rational r(numerat, denominat);
  if (r.Numerator() != 3 || r.Denominator() != 10) {
    std::cout << "Rational(3, 10) != 3/10" << std::endl;
    return 1;
  }
}

int test_2(int numerat, int denominat) {
  Rational r(numerat, denominat);
  if (r.Numerator() != 2 || r.Denominator() != 3) {
    std::cout << "Rational(8, 12) != 2/3" << std::endl;
    return 2;
  }
}

int test_3(int numerat, int denominat) {
  Rational r(numerat, denominat);
  if (r.Numerator() != -2 || r.Denominator() != 3) {
    std::cout << "Rational(-4, 6) != -2/3" << std::endl;
    return 2;
  }
}

int test_4(int numerat, int denominat) {
  Rational r(numerat, denominat);
  if (r.Numerator() != -2 || r.Denominator() != 3) {
    std::cout << "Rational(4, -6) != -2/3" << std::endl;
    return 3;
  }
}

int test_5(int numerat, int denominat) {
  Rational r(numerat, denominat);
  if (r.Numerator() != 0 || r.Denominator() != 1) {
    std::cout << "Rational(0, 15) != 0/1" << std::endl;
    return 4;
  }
}

int test_6() {
  Rational defaultConstructed;
  if (defaultConstructed.Numerator() != 0 ||
      defaultConstructed.Denominator() != 1) {
    std::cout << "Rational() != 0/1" << std::endl;
    return 5;
  }
}

int main() {
  test_1(3, 10);
  test_2(8, 12);
  test_3(-4, 6);
  test_4(4, -6);
  test_5(0, 15);
  test_6();
  std::cout << "OK" << std::endl;
  getchar();
  return 0;
}
