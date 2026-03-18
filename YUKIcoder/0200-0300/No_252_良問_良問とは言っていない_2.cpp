#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"

void Yorisou() {
  STR(s);
  int N = len(s), ans = inf<int>, mn = ans / 2, cc = 0;
  vc<u8> v(N);
  FOR(i, N - 6) {
    int c = 0;
    FOR(k, 7) c += s[i + k] != "problem"[k];
    chmin(ans, c + cc + mn);
    v[i] = !c;
    if (v[i]) ++cc;
    if (i >= 3) {
      int c = 0;
      FOR(k, 4) c += s[i - 3 + k] != "good"[k];
      FOR(k, i - 9, i + 1) if (k >= 0 and v[k]) --c;
      chmin(mn, c);
    }
  }
  print(ans);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"