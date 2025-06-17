#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  vector<PII> path;
  meion ad = [&](int x, int y) {
    path.emplace_back(x + 1, y + 1);
  };
  if (n == 1 and m == 2) {
    UL(0);
    ad(0, 0);
    ad(0, 1);
    ad(0, 0);
  } else if (n == 2 and m == 1) {
    UL(0);
    ad(0, 0);
    ad(1, 0);
    ad(0, 0);
  } else if (n == 1) {
    UL(1);
    UL(1, m, 1, 1);
    FOR(i, m) ad(0, i);
    ad(0, 0);
  } else if (m == 1) {
    UL(1);
    UL(n, 1, 1, 1);
    FOR(i, n) ad(i, 0);
    ad(0, 0);
  } else if (n == 2) {
    UL(0);
    FOR(i, m) ad(0, i);
    FOR_R(i, m) ad(1, i);
    ad(0, 0);
  } else if (m == 2) {
    UL(0);
    FOR(i, n) ad(i, 0);
    FOR_R(i, n) ad(i, 1);
    ad(0, 0);
  } else {
    bool f = 0;
    if (n & 1 ^ 1) {
      f = 1;
      swap(n, m);
    }
    FOR(i, m) ad(0, i);
    FOR(i, 1, n) ad(i, m - 1);
    FOR(i, m - 1) {
      if (i & 1) {
        ad(1, m - 2 - i);
        FOR(k, 2, n) ad(k, m - 2 - i);
      } else {
        ad(n - 1, m - 2 - i);
        FOR(k, 1, n - 1) ad(n - 1 - k, m - 2 - i);
      }
    }
    ad(0, 0);
    if (path.end()[-2] != PII{2, 1}) {
      UL(1);
      if (f) for (meion &[x, y] : path) swap(x, y);
      UL(path.end()[-2], 1, 1);
    } else {
      UL(0);
      if (f) for (meion &[x, y] : path) swap(x, y);
    }
  }
  FOR(i, len(path)) UL(path[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"