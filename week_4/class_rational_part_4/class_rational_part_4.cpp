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
    } else if (q < 0) {
      p = -p;
      q = -q;
    }
    int divider = Divider(p, q);
    p /= divider;
    q /= divider;
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

  Rational operator*(const Rational& x) {
    Rational result;
    result.p = x.p * p;
    result.q = x.q * q;
    result.SignedFactional();
    return result;
  }

  Rational operator/(const Rational& x) {
    Rational result;
    result.p = x.q * p;
    result.q = x.p * q;
    result.SignedFactional();
    return result;
  }

 private:
  int p;
  int q;
};

std::istream& operator>>(std::istream& stream, Rational& r) {
  int p_t, q_t;
  stream >> p_t;
  stream.ignore(1);
  r.Initialize(p_t, q_t);
  return stream;
}
std::ostream& operator<<(std::ostream& stream, const Rational& r) {
  stream << r.Numerator() << '/' << r.Denominator();
  return stream;
}

int main() {
  {
    const std::set<Rational> rs = {{1, 2}, {1, 25}, {9, 12}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      std::cout << "Wrong amount of items in the set" << std::endl;
      return 1;
    }
    std::vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      std::cout << "Rationals comparison works incorrectly" << std::endl;
      return 2;
    }
  }
  {
    std::map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];
    ++count[{2, 3}];
    if (count.size() != 2) {
      std::cout << "Wrong amount of items in the map" << std::endl;
      return 3;
    }
  }

  std::cout << "OK" << std::endl;
  getchar();
  return 0;
}
