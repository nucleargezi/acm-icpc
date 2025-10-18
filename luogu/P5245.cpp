#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/fps_pow.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  ll k = []() {
    mint ret;
    S(s);
    for (char c : s) {
      ret *= 10;
      ret += c - '0';
    }
    iroha ret.val;
  }();
  VEC(mint, a, n);
  UL(fps_pow(a, k));
}
#include "MeIoN_Lib/Z_H/main.hpp"