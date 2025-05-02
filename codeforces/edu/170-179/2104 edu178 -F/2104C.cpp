#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  S(s);
  set<ll> a, b;
  FOR(i, n) {
    if (s[i] == 'A') a += i + 1;
    else b += i + 1;
  }
  bool a1 = a.contains(1), an = a.contains(n);
  bool b1 = b.contains(1), bn = b.contains(n);
  ll mxa = a.empty() ? 0 : *a.rbegin();
  ll mxb = b.empty() ? 0 : *b.rbegin();
  if (mxa > mxb) {
    if (an and b1) {
      if (a.contains(n)) a -= n;
      int am = a.empty() ? 0 : *a.rbegin();
      if (b.contains(n)) b -= n;
      int bm = b.empty() ? 0 : *b.rbegin();
      Alice(am > bm);
    } else {
      Alice();
    }
  } else {
    if (bn and a1) {
      if (b.contains(1)) b -= 1;
      if (b.contains(n)) b -= n;
      Alice(b.empty());
    } else {
      Bob();
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"