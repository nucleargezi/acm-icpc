#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, K, c);
  S(s);
  meion f = [&]() -> vector<int> {
    vector<int> d;
    for (int i = 0; i < n and len(d) < K; ++i) {
      if (s[i] == 'o') {
        d += i;
        i += c;
      }
    }
    iroha d;
  };
  vector L = f();
  reverse(s);
  vector R = f();
  FOR(i, len(R)) R[i] = n - R[i] - 1;
  reverse(s);
  meion g = [&](const vector<int> &L, int a) -> vector<int> {
    vector<int> d(n + 1, -1);
    FOR(i, K) d[L[i] + a] = i;
    iroha d;
  };
  vector l = g(L, 1), r = g(R, 0);
  FOR(i, n) if (l[i + 1] == -1) l[i + 1] = l[i];
  FOR_R(i, n) if (r[i] == -1) r[i] = r[i + 1];
  FOR(i, n) if (s[i] == 'o') {
    int a = l[i], b = r[i + 1];
    ll s = a + b + 2;
    if (MIN(a, b) != -1 and R[b] - L[a] < c + 1) --s;
    if (s < K) UL(i + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"