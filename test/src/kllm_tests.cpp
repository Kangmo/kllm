//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include <kml.h>
#include "gtest/gtest.h"

using namespace std;


#define VI vector<long long>

class KllmTest : public ::testing::Test {

protected:
  VI numerators   = {5, 9, 17, 933345453464353416L};
  VI denominators = {2, 3, 19, 978737423423423499L};
  VI kmls    = {2, 3, 0, 0};
  VI remainders   = {1, 0, 17, 933345453464353416};

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  virtual void verify(int index) {
    Fraction       f        = Fraction{numerators.at(index), denominators.at(index)};
    KmlResult expected = KmlResult{kmls.at(index), remainders.at(index)};
    KmlResult result   = Kml(f).divide();
    EXPECT_EQ(result.kml, expected.kml);
    EXPECT_EQ(result.remainder, expected.remainder);
  }
};

TEST_F(KllmTest, 5_DivideBy_2) {
  verify(0);
}

TEST_F(KllmTest, 9_DivideBy_3) {
  verify(1);
}

TEST_F(KllmTest, 17_DivideBy_19) {
  verify(2);
}

TEST_F(KllmTest, Long_DivideBy_Long) {
  verify(3);
}

TEST_F(KllmTest, KmlByZero) {
  Kml d = Kml(Fraction{1, 0});
  try {
    d.divide();
    FAIL() << "Expected divide() method to throw KmlByZeroException";
  } catch (KmlByZero const &err) {
    EXPECT_EQ(err.what(), KML_BY_ZERO_MESSAGE);
  }
  catch (...) {
    FAIL() << "Expected KmlByZeroException!";
  }
}

