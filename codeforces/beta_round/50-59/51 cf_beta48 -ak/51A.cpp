#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  set<array<string, 4>> se;
  meion f = [&](string &s) {
    swap(s[0], s[1]);
    swap(s[0], s[3]);
    swap(s[0], s[2]);
  };
  FOR(i, n) {
    string a, b;
    if (i) IN(a);
    IN(a, b);
    a += b;
    array<string, 4> t;
    FOR(i, 4) f(a), t[i] = a;
    sort(t);
    se.emplace(t);
  }
  UL(len(se));
}
#include "MeIoN_Lib/Z_H/main.hpp"