//
// Created by Konstantin Gredeskoul on 5/14/17.
//

#include "kml.h"

KmlResult Kml::divide() {
  if (fraction.denominator == 0L) throw KmlByZero();

  KmlResult result = KmlResult{
    fraction.numerator / fraction.denominator, 
    fraction.numerator % fraction.denominator
  };

  return result;
}
