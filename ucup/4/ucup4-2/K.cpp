#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/wave/wave_mat.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/ds/monoid/mul.hpp"
#include "YRS/ds/static_range_group.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(int, y, N);
  vector<ll> w(y.begin(), y.end());
  int mx = QMAX(w) + 1;
  FOR(i, N) --w[i];
  wave_matrix<int, false, static_range_group<monoid_add<ll>>> seg(y, w);
  vector<mint> ww(N);
  FOR(i, N) ww[i] = w[i] + 1;
  wave_matrix<int, false, static_range_group<monoid_mul<mint>>> seg_mul(y, ww);
  FOR(Q) {
    INT(l, r);
    LL(K);
    --l;
    Z [c, sz, prod] = seg.max_right([&](int c, int sz, ll prod) -> bool {
      return prod <= K; 
    }, l, r);
    chmin(c, mx);
    int cut = seg.count(l, r, c, c + 1);
    mint ans = seg_mul.prod(l, r, c + 1, mx);
    ll pr_sum = seg.pre_prod(l, r, c);
    K -= pr_sum;
    if (cut != 0) {
      ll a = K / (c - 1);
      K %= c - 1;
      cut -= a;
      if (cut > 0) {
        if (K) --cut, ans *= (c - K);
        ans *= mint(c).pow(cut);
      }
    }
    print(ans.val);
  }
}
#include "YRS/Z_H/main.hpp"