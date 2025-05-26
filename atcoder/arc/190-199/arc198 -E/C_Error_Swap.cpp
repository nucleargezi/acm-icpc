#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  if (SUM(a) != SUM(b)) iroha No();
  vector<PII> ans;
  meion f = [&](int i, int k) -> void {
    ans += PII(i + 1, k + 1);
    std::tie(a[i], a[k]) = PII(a[k] - 1, a[i] + 1);
  };
  meion sp = [&](int i, int k) -> void {
    f(0, i);
    f(0, k);
    f(0, i);
  };
  meion sp2 = [&]() {
    f(1, 2);
    f(0, 2);
    f(1, 2);
  };
  if (n == 2) {
    if (a != b) {
      f(0, 1);
      if (a != b) iroha No();
      iroha Yes(), UL(1), UL(ans);
    } else {
      iroha Yes(), UL(0);
    }
  }
  if (a[0] > b[0]) {
    while (a[0] != b[0]) {
      sp2();
      f(0, 1);
    }
  } else if (a[0] < b[0]) {
    while (a[0] != b[0]) {
      f(0, 1);
      sp2();
    }
  }
  FOR(i, 1, n) {
    if (a[i] > b[i]) {
      FOR(k, i + 1, n) if (a[k] < b[k]) {
        while (a[k] < b[k] and a[i] > b[i]) {
          sp(i, k);
          f(i, k);
        }
        if (a[i] == b[i]) break;
      }
    } else if (a[i] < b[i]) {
      FOR(k, i + 1, n) if (a[k] > b[k]) {
        while (a[k] > b[k] and a[i] < b[i]) {
          f(i, k);
          sp(i, k);
        }
        if (a[i] == b[i]) break;
      }
    }
  }
  Yes();
  UL(len(ans));
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"