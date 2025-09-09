#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  S(s);
  static constexpr string h = "hello";
  int t = 0;
  for (char c : s) {
    if (t < 5 and c == h[t]) ++t;
  }
  YES(t == 5);
}
#include "YRS/Z_H/main.hpp"