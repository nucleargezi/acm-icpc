#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  mint s = 0;
  vector<ll> st;
  LL(n);
  FOR(n) {
    S(op);
    if (op == "Push") {
      LL(x);
      s += x;
      st += x;
    } else if (op == "Repeat") {
      s += s;
      if (len(st) < n) st += st;
    } else {
      s -= pop(st);
    }
    UL(s);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"