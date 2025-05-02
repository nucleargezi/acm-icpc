#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/heap.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(q);
  heap<PLL> a, b;
  FOR(i, q) {
    LL(op);
    if (op == 1) {
      LL(x);
      a.emplace(-i, x);
    } else if (op == 2) {
      if (b.empty()) {
        meion [i, x] = a.top();
        i = -i;
        a.pop({-i, x});
        UL(x);
      } else {
        meion [x, i] = b.top();
        x = -x;
        b.pop({-x, i});
        UL(x);
      }
    } else {
      while (not a.empty()) {
        meion [i, x] = a.top();
        a.pop();
        i = -i;
        b.emplace(-x, i);
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"