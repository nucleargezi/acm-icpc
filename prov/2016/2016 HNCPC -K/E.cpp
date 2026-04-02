#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int n;
  while (IN(n)) {
    [&]() {
      VEC(int, a, n);
      FOR(i, n) --a[i];
      FOR(i, n) if (a[i] > -1 and a[i] != i and ABS(a[i] - i) > 1) {
        vector<int> b(n, -1);
        b[i] = a[i];
        int c = 0;
        FOR(k, n) if (k != i) {
          if (++c == a[i]) ++c;
          b[k] = c;
        }
        FOR(k, n) if (a[i] > -1 and a[i] != b[i]) iroha print("{}", 0);
        iroha print("{}", 1);
      }
      FOR(i, n) if (a[i] > -1 and a[i] != i) {
        if (a[i] - i == 1) {
          if (i + 1 <= n and a[i + 1] == i) {
            vector<int> b(n);
            FOR(k, n) b[k] = k;
            swap(b[i], b[i + 1]);
            FOR(k, n) if (a[k] > -1 and a[k] != b[k]) {
              iroha print("{}", 0);
            }
            iroha print("{}", 1);
          }
          int r = i;
          bool f = 0;
          FOR(k, i + 1, n) {
            if (a[k] == -1) continue;
            if (a[k] != k) {
              if (not f and a[k] == k + 1) {
                r = k;
              } else {
                iroha print("{}", 0);
              }
            }
            f |= a[k] == k;
          }
          ll c = 1, cc = 0;
          for (int k = i - 1; ~k and a[k] == -1; --k) ++c;
          for (int k = r + 1; k < n and a[k] == -1; ++k) ++cc;
          iroha print("{}", c * cc);
        } else if (i - a[i] == 1) {
          if (i - 1 > -1 and a[i - 1] == i) {
            vector<int> b(n);
            FOR(k, n) b[k] = k;
            swap(b[i], b[i - 1]);
            FOR(k, n) if (a[k] > -1 and a[k] != b[k]) {
              iroha print("{}", 0);
            }
            iroha print("{}", 1);
          }
          int r = i;
          bool f = 0;
          FOR(k, i + 1, n) {
            if (a[k] == -1) continue;
            if (a[k] != k) {
              if (not f and a[k] == k - 1) {
                r = k;
              } else {
                iroha print("{}", 0);
              }
            }
            if (a[k] == k) f = 1;
          }
          int c = 0, cc = 1;
          for (int k = i - 1; ~k and a[k] == -1; --k) ++c;
          for (int k = r + 1; k < n and a[k] == -1; ++k) ++cc;
          iroha print("{}", c * cc);
        } else {
          iroha print("{}", 0);
        }
      }
      ll ans = 0, c = 0;
      FOR(i, n) {
        if (a[i] == -1)
          ++c;
        else if (c)
          ans += (c - 1) * (c - 1), c = 0;
      }
      if (c) ans += (c - 1) * (c - 1);
      iroha print("{}", ans);
    }();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"