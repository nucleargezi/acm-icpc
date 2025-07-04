#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  S(s);
  set<int> ba, bc, ca, cb;
  FOR(i, q) {
    CH(f, t);
    if (f == 'b' and t == 'a') ba += i;
    if (f == 'b' and t == 'c') bc += i;
    if (f == 'c' and t == 'a') ca += i;
    if (f == 'c' and t == 'b') cb += i;
  }
  int p = -1;
  FOR(i, n) {
    if (s[i] == 'b') {
      if (not ba.empty()) {
        s[i] = 'a';
        ba.extract(ba.begin());
      } else {
        if (not bc.empty()) {
          int x = *bc.begin();
          meion it = ca.upper_bound(x);
          if (it != ca.end()) {
            bc.extract(x);
            ca.extract(it);
            s[i] = 'a';
          }
        }
      }
    } else if (s[i] == 'c') {
      if (not ca.empty()) {
        ca.extract(ca.begin());
        s[i] = 'a';
      } else {
        if (cb.empty()) continue;
        int x = *cb.begin();
        cb.extract(x);
        meion it = ba.upper_bound(x);
        if (it != ba.end()) {
          ba.extract(it);
          s[i] = 'a';
        } else {
          s[i] = 'b';
        }
      }
    }
  }
  UL(s);
}
#include "MeIoN_Lib/Z_H/main.hpp"