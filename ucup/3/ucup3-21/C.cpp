#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
struct Seg {
  int N;
  vector<ll> a, f;

  Seg(int n) : N(1 << n), a(N << 1) {
    FOR(i, 1, N + N) IN(a[i]);
    f = a;
    FOR_R(i, 1, N) upd(i);
  }
  
  void set(int i, ll x) {
    f[i] = a[i] = x;
    if (i < N) upd(i);
    while (i >>= 1) upd(i);
  }

  ll prod(int l, int r) {
    if (l == r) return 0;
    l += N, r += N - 1;
    ll ls = 0, rs = f[l], LS = f[r], RS = 0, ans = inf<ll>;
    while (l != 1) {
      make(l, ls, rs), make(r, LS, RS);
      l >>= 1, r >>= 1;
      if (l != r and l / 2 == r / 2) chmin(ans, rs + LS);
      if (l == r) chmin(ans, ls + LS), chmin(ans, rs + RS);
    }
    return ans;
  }

  void upd(int i) {
    f[i] = f[i << 1] + f[i << 1 | 1];
    chmin(f[i], a[i]);
  }

  void make(int i, ll &l, ll &r) {
    if (i & 1) l += f[i - 1];
    else r += f[i + 1];
    chmin(l, r + f[i >> 1]);
    chmin(r, l + f[i >> 1]);
  }
};
void Yorisou() {
  INT(n);
  Seg seg(n);
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(j);
      LL(x);
      seg.set(j, x);
    } else {
      INT(s, t);
      print(seg.prod(s, t));
    }
  }
}
#include "YRS/Z_H/main.hpp"