#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(x, y, xx, yy, s, t);
  string to_zero, go, val;
  meion U = [&]() {
    ++y;
    go += "W";
  };
  meion D = [&]() {
    --y;
    go += "S";
  };
  meion L = [&]() {
    --x;
    go += "DWAAS";
  };
  meion R = [&]() {
    ++x;
    go += "AWDDS";
  };
  meion R100 = [&]() {
    x += 100;
    go += "AWWWWWWW";
    FOR(i, 101) go += "D";
    go += "SSSSSSS";
  };
  meion L100 = [&]() {
    x -= 100;
    go += "DWWWWWWW";
    FOR(i, 101) go += "A";
    go += "SSSSSSS";
  };
  while (s) s /= 2, --y, to_zero += "S";
  FOR_R(i, 32) {
    val += 'W';
    s <<= 1;
    ++y;
    if (t >> i & 1) {
      val += 'D';
      ++s;
      ++x;
    }
  }
  while (x + 100 < xx) R100();
  while (x > xx + 100) L100();
  while (x < xx) R();
  while (x > xx) L();
  while (y < yy) U();
  while (y > yy) D();
  UL(to_zero + go + val);
}
#include "MeIoN_Lib/Z_H/main.hpp"