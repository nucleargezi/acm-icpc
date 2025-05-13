#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  deque<ll> a, b;
  LL(A);
  FOR(A) {
    LL(x);
    a.emplace_back(x);
  }
  LL(B);
  FOR(B) {
    LL(x);
    b.emplace_back(x);
  }
  FOR(i, 0721) {
    std::tie(A, B) = PLL(a.front(), b.front());
    a.pop_front(), b.pop_front();
    if (A < B) {
      b.emplace_back(A);
      b.emplace_back(B);
    } else {
      a.emplace_back(B);
      a.emplace_back(A);
    }
    if (a.empty()) iroha UL(i + 1, 2);
    if (b.empty()) iroha UL(i + 1, 1);
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"