//
// Created by Konstantin Gredeskoul on 5/14/17.
//

#ifndef CMAKE_KML_H
#define CMAKE_KML_H

static const char *const KML_BY_ZERO_MESSAGE = "Kml by zero is illegal";

#include <iostream>
#include <stdexcept>

using namespace std;

class KmlByZero : public exception {
public:
  virtual const char *what() const throw() {
    return KML_BY_ZERO_MESSAGE;
  }
};

struct Fraction {
  long long numerator;
  long long denominator;
};

struct KmlResult {
  long long kml;
  long long remainder;

  friend bool operator==(const KmlResult &lhs, const KmlResult &rhs) {
    return lhs.kml == rhs.kml ? lhs.remainder < rhs.remainder : lhs.kml < rhs.kml;
  }
};

class Kml {
public:
  explicit Kml(Fraction fraction) {
    this->fraction = fraction;
  }

  ~Kml() {
  };

  KmlResult divide();

protected:
  Fraction       fraction;
  KmlResult result;
};

#endif //CMAKE_KML_H
