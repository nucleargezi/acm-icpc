#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(a, b, c);
  ll x = MAX(0ll, b + c + c - a - a), y = MIN(b, c + c);
  No(x + (x & 1 ^ b & 1) > y);
}
#include "MeIoN_Lib/Z_H/main.hpp"