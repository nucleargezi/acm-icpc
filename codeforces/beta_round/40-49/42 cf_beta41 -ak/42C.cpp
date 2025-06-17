#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  VEC(ll, a, 4);
  ll ans = 0;
  struct X {
    int n;
    X(int t) : n(t) {}
    int operator[](int x) { iroha x + n & 3; }
  } L(3), R(1);
  ll mx = QMAX(a);
  while (mx != 1) {
    int i = 0;
    for (; i < 4; ++i) {
      if (a[i] == mx) break;
    }
    if (a[i] & 1) {
      if (a[L[i]] & 1) {
        UL("+" + to_str(L[i] + 1));
        UL("/" + to_str(L[i] + 1));
        a[L[i]] = a[L[i]] + 1 >> 1;
        a[i] = a[i] + 1 >> 1;
      } else if (a[R[i]] & 1) {
        UL("+" + to_str(i + 1));
        UL("/" + to_str(i + 1));
        a[i] = a[i] + 1 >> 1;
        a[R[i]] = a[R[i]] + 1 >> 1;
      } else {
        UL("+" + to_str(i + 1));
        UL("/" + to_str(L[i] + 1));
        a[i] = a[i] + 1 >> 1;
        a[R[i]] += 1;
        a[L[i]] = a[L[i]] >> 1;
      }
    } else {
      if (a[L[i]] & 1 ^ 1) {
        UL("/" + to_str(L[i] + 1));
        a[i] >>= 1;
        a[L[i]] >>= 1;
      } else if (a[R[i]] & 1 ^ 1) {
        UL("/" + to_str(i + 1));
        a[i] >>= 1;
        a[R[i]] >>= 1;
      } else {
        UL("+" + to_str(L[i] + 1));
        UL("+" + to_str(i + 1));
        UL("/" + to_str(L[i] + 1));
        a[L[i]] = a[L[i]] + 1 >> 1;
        a[i] = a[i] + 2 >> 1;
        a[R[i]] += 1;
      }
    }
    mx = QMAX(a);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"