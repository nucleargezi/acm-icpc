#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_act.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
vector<int> dis;
struct MX {
  using X = struct dat {
    int id, x, p[4];
    int &operator[](int i) { return p[i]; }
  };
  static X unit() { return {-1, 0, {-1, -1, -1, -1}}; }
  static X make(int i, int x) {
    X r = unit();
    r.id = i, r.x = x;
    r[x] = i;
    return r;
  }
  static int cp(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return dis[a] > dis[b] ? a : b;
  }
  static X op(X a, X b) {
    X r = a;
    FOR(i, 4) r[i] = cp(a[i], b[i]);
    return r;
  }
};
struct MA {
  using X = int;
  static constexpr X unit() { return 0; }
  static constexpr X op(X a, X b) { return a + b; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static X act(X x, A a, int) {
    X r = x;
    r.x += a;
    FOR(i, 4) r[i] = -1;
    FOR(i, 4) if(i + a < 4 and i + a > -1) r[i + a] = x[i];
    return r;
  }
};
using X = MX::X;
using A = MA::X;
using LCT = LCT_act_commute<AM>;
void Yorisou() {
  INT(N);
  const int sz = N * 3 + 1;
  dis.resize(sz);
  LCT lct(sz);
  vector<int> fa(sz, -1);
  vector<vector<int>> v(sz);
  FOR(i, N) FOR(3) {
    INT(x);
    --x;
    fa[x] = i;
    v[i].ep(x);
  }
  vector<int> col(sz), s(sz);
  FOR(i, N, sz) IN(col[i]);
  FOR(i, N) if (s[i] > 1) col[i] = 1;
  Z f = [&](Z &f, int n) -> void {
    for (int x : v[n]) {
      dis[x] = dis[n] + 1;
      f(f, x);
      s[n] += col[x];
    }
    if(s[n] > 1) col[n] = 1;
  };
  f(f, 0);
  FOR(i, sz) lct.a[i].mx = MX::make(i, s[i]);
  FOR(i, sz) for (int x : v[i]) lct.link(i, x);

  INT(Q);
  int ans = col[0];
  FOR(Q) {
    INT(x);
    --x;
    col[x] ^= 1;
    int f = fa[x];
    Z dat = lct.prod(f, 0);
    int a = -1;
    FOR(i, 4) if (i != 2 - col[x]) a = MX::cp(a, dat[i]);
    if (a == -1) a = 0, ans ^= 1;
    lct.apply(f, a, col[x] ? 1 : -1);
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"