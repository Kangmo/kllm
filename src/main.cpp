#include <kml.h>
#include <iostream>

using namespace std;

static const char *const HEADER = "\nKllm © 2018 Monkey Claps Inc.\n\n";
static const char *const USAGE = "Usage:\n\tkllm <numerator> <denominator>\n\nDescription:\n\tComputes the result of a fractional kml,\n\tand reports both the result and the remainder.\n";

int main(int argc, const char *argv[]) {
  Fraction f;

  cout << HEADER;

  // ensure the correct number of parameters are used.
  if (argc < 3) {
    cout << USAGE;
    return 1;
  }

  f.numerator = atoll(argv[1]);
  f.denominator = atoll(argv[2]);

  Kml d = Kml(f);
  try {
    KmlResult r = d.divide();

    cout << "Kml : " << f.numerator << " / " << f.denominator << " = " << r.kml << "\n";
    cout << "Remainder: " << f.numerator << " % " << f.denominator << " = " << r.remainder << "\n";
  } catch (KmlByZero) {
    cout << "Can not divide by zero, Homer. Sober up!\n";
  }
  return 0;
}
