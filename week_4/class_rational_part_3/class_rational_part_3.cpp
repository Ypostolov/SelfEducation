#include <iostream>
#include <sstream>

class Rational {
 public:
  Rational() {
    // Реализуйте конструктор по умолчанию
    p = 0;
    q = 1;
    divider = 1;
  }

  Rational(int numerator, int denominator) {
    Initialize(numerator, denominator);
  }

  void Initialize(const int& n, const int& d) {
    p = n;
    q = d;
    SignedFactional();
    p = Numerator();
    q = Denominator();
  }

  int GetP() const {
    return p;
  }

  int GetQ() const {
    return q;
  }

  void SignedFactional() {
    if (p == 0) {
      q = 1;
    } else if (p < 0 && q < 0) {
      p = abs(p);
      q = abs(q);
    } else if (p < 0 || q < 0) {
      p = abs(p) * (-1);
      q = abs(q);
    }
    divider = Divider();
  }

  int Divider() {
    if (p == q) {
      return p;
    } else if (p == 0 && q != 0) {
      return q;
    } else if (p != 0 && q == 0) {
      return p;  // bad case!
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

  const bool operator==(const Rational& a) const {
    if ((a.p == p) && (a.q == q))
      return true;
    else
      return false;
  }

  Rational operator+(const Rational& x) {
    Rational result;
    if (x.q == q) {
      result.p = x.p + p;
      result.q = x.q;
    } else {
      result.p = (x.p * q) + (p * x.q);
      result.q = x.q * q;
    }
    result.SignedFactional();
    result.p = result.Numerator();
    result.q = result.Denominator();
    return result;
  }

  Rational operator-(const Rational& x) {
    Rational result;
    if (x.q == q) {
      result.p = p - x.p;
      result.q = x.q;
    } else {
      result.p = (p * x.q) - (x.p * q);
      result.q = x.q * q;
    }
    result.SignedFactional();
    result.p = result.Numerator();
    result.q = result.Denominator();
    return result;
  }

  Rational operator*(const Rational& x) {
    Rational result;
    result.p = x.p * p;
    result.q = x.q * q;
    result.SignedFactional();
    result.p = result.Numerator();
    result.q = result.Denominator();
    return result;
  }

  Rational operator/(const Rational& x) {
    Rational result;
    result.p = x.q * p;
    result.q = x.p * q;
    result.SignedFactional();
    result.p = result.Numerator();
    result.q = result.Denominator();
    return result;
  }

 private:
  int divider;
  int p;
  int q;
};

std::istream& operator>>(std::istream& stream, Rational& r) {
  int p_t, q_t;
  stream >> p_t;
  stream.ignore(1);  // ignore ':'
  stream >> q_t;
  r.Initialize(p_t, q_t);
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const Rational& r) {
  stream << r.GetP() << '/' << r.GetQ();
  return stream;
}

int main() {
  {
    std::ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
      return 1;
    }
  }
  {
    std::istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      std::cout << "5/7 is incorrectly read as " << r << std::endl;
      return 2;
    }
  }
  {
    std::istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2
                << std::endl;
      return 3;
    }
  }
  std::cout << "OK" << std::endl;
  getchar();
  return 0;
}
