#include "YRS/all.hpp"
#include "YRS/ds/lct/LCT_act.hpp"
#include "YRS/ds/lct/node_acted.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
vector<int> dis;
struct MX {
  using X = struct dat {
    int id, x, p[4];
    int &operator[](int i) { return p[i]; }
  };

  static X unit() { return {-1, 0, {-1, -1, -1, -1}}; }

  static X make(int i, int x) { 
    X res = unit();
    res.id = i, res.x = x;
    res[0] = res[1] = res[2] = res[3] = -1;
    res[x] = i;
    return res;
  }
  
  static int cp(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return dis[a] > dis[b] ? a : b;
  }
  
  static X op(X a, X b) {
    X res = a;
    FOR(i, 4) res[i] = cp(a[i], b[i]);
    return res;
  }
};
struct mono {
  using MX = ::MX;
  using MA = monoid_add<int>;
  using X = MX::X;
  using A = MA::X;

  static X act(X x, A a, ll) {
    X res = x;
    res.x += a;
    FOR(i, 4) res[i] = -1;
    FOR(i, 4) if (i + a < 4 and i + a > -1) res[i + a] = x[i];
    return res;
  }
};
using DS = LCT_act<lct_node_acted<mono>>;
void Yorisou() {
  INT(N);
  const int sz = N * 3 + 1;
  dis.resize(sz);
  DS lct(sz);
  vector<int> fa(sz, -1);
  vector<vector<int>> v(sz);
  FOR(i, N) FOR(3) {
    INT(x);
    --x;
    lct.link(i, x);
    fa[x] = i;
    v[i].ep(x);
  }
  lct.evert(0);
  FOR(i, 1, sz) dis[i] = lct.depth(i);
  vector<int> col(sz), s(sz);
  FOR(i, N, sz) IN(col[i]);
  FOR(i, N) if (s[i] > 1) col[i] = 1;
  Z f = [&](Z &f, int n) -> void {
    for (int t : v[n]) {
      f(f, t);
      s[n] += col[t];
    }
    if (s[n] > 1) col[n] = 1;
  };
  f(f, 0);
  int ans = col[0];
  FOR(i, sz) lct.set(i, MX::make(i, s[i]));
  INT(Q);
  FOR(Q) {
    INT(x);
    --x;
    col[x] ^= 1;
    int f = fa[x];
    Z dat = lct.prod_path(f, 0);
    int a = -1;
    FOR(i, 4) if (i != 2 - col[x]) a = MX::cp(a, dat[i]);
    if (a == -1) a = 0, ans ^= 1;
    // else a = lct.jump(a, x, 1);
    lct.apply_path(f, a, col[x] ? 1 : -1);
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"