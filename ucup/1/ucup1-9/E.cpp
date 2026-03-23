#include "YRS/all.hpp"

void Yorisou() {
  LL(N, M);
  VEC(int, a, N);
  vc<ll> c(N + 1);
  print(bina([&](ll A) -> bool {
    if (not A) return 1;
    fill(all(c), 0);
    FOR(i, N) c[i] = ceil<ll>(A, a[i]);
    ll s = M;
    FOR(i, N) {
      if (c[i] == 0) {
        if (i + 1 == N) break;
      } else {
        c[i] -= 1;
      }
      --s;
      c[i + 1] -= c[i];
      s -= c[i] << 1;
      c[i] = 0;
      chmax(c[i + 1], 0);
      if (s < 0) return 0;
    }
    return s >= 0;
  }, 0, QMIN(a) * M + 1));
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"