#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr int sz = 18;
void Yorisou() {
  LL(N, K, Q);
  VEC(ll, a, N);
  retsu<ll> L(N, sz), R(L);
  FOR(i, N - 1) {
    ll l = a[i] % K, r = a[i + 1] % K, d = (l <= r ? r - l : K - (l - r));
    R[i][0] = d;
  }
  FOR(d, 1, sz) FOR(i, N) {
    R[i][d] = R[i][d - 1] + ((i + (1 << (d - 1)) < N) ? R[i + (1 << (d - 1))][d - 1] : 0);
  }
  FOR(i, 1, N) {
    ll l = a[i] % K, r = a[i - 1] % K, d = (l <= r ? r - l : K - (l - r));
    L[i][0] = d;
  }
  FOR(d, 1, sz) FOR(i, N) L[i][d] = L[i][d - 1] + ((i - (1 << (d - 1)) >= 0) ? L[i - (1 << (d - 1))][d - 1] : 0);
  FOR(Q) {
    LL(x, y, xx, yy);
    --x, --xx;
    if (y <= a[x]) {
      if (yy <= a[xx]) print(abs(x - xx));
      else {
        y = a[x];
        if (y >= yy) print(abs(x - xx));
        else goto MyGO;
      }
    } else if (yy <= a[xx]) {
      yy = a[xx];
      if (yy >= y) print(abs(x - xx));
      else goto MyGO;
    } else {
      MyGO: 
      if (y > yy) swap(x, xx), swap(y, yy);
      if ((y - a[x]) % K) y += K - (y - a[x]) % K;
      ll s = 0, p = x;
      if (x < xx) {
        FOR(i, sz) if ((xx - x) >> i & 1) s += R[p][i], p += 1 << i;
      } else {
        FOR(i, sz) if ((x - xx) >> i & 1) s += L[p][i], p -= 1 << i;
      }
      y += s;
      ll rs = abs(x - xx);
      if (y < yy) rs += ceil(yy - y, K);
      print(rs);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}