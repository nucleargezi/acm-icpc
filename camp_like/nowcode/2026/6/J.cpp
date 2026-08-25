#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/ge/basic/hull.hpp"
#include "YRS/ds/seg/seg_t.hpp"

bool cmp(var a, var b) { return 1ll * a.fi * b.se < 1ll * a.se * b.fi; }

struct MX {
  using X = pair<PII, int>;
  static X op(const X &a, const X &b) { 
    if (a.se == -1) return b;
    if (b.se == -1) return a;
    return cmp(a.fi, b.fi) ? b : a; 
  }
  static X unit() { return {{}, -1}; }
};

PII me(var a, var b) { return {a.fi + b.fi, a.se + b.se}; }

void cmax(PII &a, var b) {
  if (b.fi == -1) return;
  if (a.fi == -1) a = b;
  else if (1ll * a.fi * b.se < 1ll * a.se * b.fi) a = b;
}

pair<PII, int> fib_search(Z f, int l, int r) {
  assert(l < r);
  --r;
  int a = l - 1, x, b, s = 1, t = 2;
  while (t < r - l + 2) swap(s += t, t);
  x = a + t - s, b = a + t;
  PII fx = f(x), fy;
  while (a + b != 2 * x) {
    int y = a + b - x;
    if (r < y or (fy = f(y), cmp(fy, fx))) {
      b = a, a = y;
    } else {
      a = x, x = y, fx = fy;
    }
  }
  return {fx, x};
}

using P = point<ll>;
void Yorisou() {
  INT(N, Q);
  vc<PII> a(N);
  FOR(i, N) IN(a[i].fi);
  FOR(i, N) IN(a[i].se);
  seg_t<MX> seg(N, [&](int i) -> MX::X { return {a[i], i}; });

  const int B = 200, sz = ceil(N, B);
  vc<vc<int>> hs(sz);
  Z set = [&](int i) {
    int l = i * B, r = l + B;
    chmin(r, N);
    static vc<P> g;
    g.clear();
    FOR(i, l, r) g.ep(a[i].fi, a[i].se);
    hs[i] = hull<ll, 0, 1>(g);
    for (int &x : hs[i]) x += l;
  };

  FOR(i, sz) set(i);
  Z slv = [&](PII p, int l, int r) -> PII {
    int ls = l / B, rs = (r - 1) / B;
    PII ans{-1, -1};
    while (l < r and l / B == ls) cmax(ans, me(p, a[l])), ++l;
    while (l < r and (r - 1) / B == rs) --r, cmax(ans, me(p, a[r]));
    FOR(i, ls + 1, rs) {
      var s = hs[i];
      int l = 0, r = si(s);
      if (l >= r) continue;
      PII fx = fib_search([&](int i) { return me(a[s[i]], p); }, l, r).fi;
      cmax(ans, fx);
    }
    return ans;
  };
  
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      a[--i].fi = x;
      set(i / B);
      seg.set(i, {a[i], i});
    } else if (op == 2) {
      INT(i, x);
      a[--i].se = x;
      set(i / B);
      seg.set(i, {a[i], i});
    } else {
      INT(l, r);
      --l;
      Z [p, mx] = seg.prod(l, r);
      Z a = slv(p, l, mx);
      Z b = slv(p, mx + 1, r);
      cmax(a, b);
      Z [x, y] = a;
      int g = gcd(x, y);
      x /= g, y /= g;
      print(x, y);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}