#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

int Divider(const int& n, const int& d) {
  if (n == d) {
    return n;
  } else if (n == 0) {
    return n;
  } else {
    int dividend_t = 0;
    int divider_t = 0;
    int reminder = 0;
    if (n > d) {
      dividend_t = n;
      divider_t = d;
    } else {
      dividend_t = d;
      divider_t = n;
    }
    reminder = dividend_t % divider_t;
    while (reminder != 0) {
      dividend_t = divider_t;
      divider_t = reminder;
      reminder = dividend_t % divider_t;
    }
    if (divider_t < 0)
      return -divider_t;
    else
      return divider_t;
  }
}

class Rational {
 public:
  Rational() {
    p = 0;
    q = 1;
  }
  Rational(int numerator, int denominator) {
    if (denominator == 0) {
      throw std::invalid_argument("R u fckn srsly?!");
    } else
      Initialize(numerator, denominator);
  }
  void Initialize(const int& n, const int& d) {
    p = n;
    q = d;
    SignedFactional();
  }
  void SignedFactional() {
    if (p == 0) {
      q = 1;
    } else {
      if (q < 0) {
        p = -p;
        q = -q;
      }
      int divider = Divider(p, q);
      p /= divider;
      q /= divider;
    }
  }

  int Numerator() const {
    return p;
  }
  int Denominator() const {
    return q;
  }
  const bool operator==(const Rational& a) const {
    if ((a.p == p))
      return true;
    else
      return false;
  }
  const bool operator>(const Rational& a) const {
    if ((p * a.q) > (q * a.p))
      return true;
    else
      return false;
  }
  const bool operator<(const Rational& a) const {
    if ((p * a.q) < (q * a.p))
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
    return result;
  }

  friend std::istream& operator>>(std::istream& stream, Rational& r) {
    int p_t, q_t;
    stream >> p_t;
    stream.ignore(1);  // ignore '/'
    stream >> q_t;
    r.Initialize(p_t, q_t);
    return stream;
  }

  friend std::ostream& operator<<(std::ostream& stream, const Rational& r) {
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
  }
  friend Rational operator*(const Rational& left, const Rational& right) {
    Rational result;
    result.Initialize((right.Numerator() * left.Numerator()),
                      (right.Denominator() * left.Denominator()));
    return result;
  }
  friend Rational operator/(const Rational& left, const Rational& right) {
    if (right.Numerator() == 0) {
      throw std::domain_error("Achtung!");
    } else {
      Rational result;
      result.Initialize((left.Numerator() * right.Denominator()),
                        (left.Denominator() * right.Numerator()));
      return result;
    }
  }

 private:
  int p;
  int q;
};

int main() {
  try {
    Rational r(1, 0);
    std::cout << "Doesn't throw in case of zero denominator" << std::endl;
    return 1;
  } catch (std::invalid_argument&) {
  }
  try {
    auto x = Rational(1, 2) / Rational(0, 1);
    std::cout << "Doesn't throw in case of division by zero" << std::endl;
    return 2;
  } catch (std::domain_error&) {
  }

  std::cout << "OK" << std::endl;
  getchar();
  return 0;
}
