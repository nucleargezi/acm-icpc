#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/frac_cas/frac_cas_seg.hpp"

struct DS {
  struct X { ll s; int l, r; };
  const int N, B, K;
  vc<int> a, rk, pos;
  vc<vc<X>> dat;
  frac_cas_seg<int, 6> g;
  vc<vc<int>> cut(var a, int B) {
    int K = (si(a) + B - 1) / B;
    vc<vc<int>> b(K);
    FOR(i, si(a)) b[i / B].ep(a[i]);
    FOR(i, K) sort(b[i]);
    return b;
  }
  DS(const vc<int> &b, int c = 600)
      : N(si(b)), B(c), K((N + B - 1) / B), a(b),
        rk(N), pos(N), dat(K), g(cut(a, B)) {
    FOR(i, K) {
      int l = i * B, n = sz(i);
      vc<int> p(n);
      iota(all(p), l);
      sort(p, [&](int x, int y) {
        return a[x] < a[y] or (a[x] == a[y] and x < y);
      });
      FOR(k, n) pos[l + k] = p[k], rk[p[k]] = k;
      build(i);
    }
  }
  int sz(int b) { return min(B, N - b * B); }
  void build(int b) {
    int l = b * B, n = sz(b);
    vc<int> f(n);
    X c{};
    dat[b].resize(n + 1), dat[b][0] = c;
    FOR(i, n) {
      int p = pos[l + i] - l, x = p ? f[p - 1] : 0, y = p + 1 < n ? f[p + 1] : 0;
      f[p - x] = f[p + y] = x + y + 1;
      c.s += 1ll * (x + 1) * (y + 1);
      c.l = f[0], c.r = f[n - 1];
      dat[b][i + 1] = c;
    }
  }
  void set(int p, int x) {
    if (a[p] == x) return;
    int b = p / B, l = b * B, k = rk[p], n = sz(b);
    Z &v = g[b];
    if (x < a[p]) {
      while (k and x < v[k - 1]) {
        v[k] = v[k - 1], pos[l + k] = pos[l + k - 1], rk[pos[l + k]] = k, --k;
      }
    } else {
      while (k + 1 < n and v[k + 1] < x) {
        v[k] = v[k + 1], pos[l + k] = pos[l + k + 1], rk[pos[l + k]] = k, ++k;
      }
    }
    a[p] = v[k] = x, pos[l + k] = p, rk[p] = k;
    g.rebuild(b), build(b);
  }
  ll prod(int l, int r, int x) {
    ll s = 0;
    int c = 0;
    Z f = [&](int l, int r) {
      FOR(i, l, r) {
        if (a[i] <= x) s += ++c;
        else c = 0;
      }
    };
    int ls = l / B, rs = (r - 1) / B;
    if (ls == rs) f(l, r);
    else {
      f(l, (ls + 1) * B);
      g.ub(ls + 1, rs, x, [&](int i, int k) {
        var d = dat[i][k];
        int n = sz(i);
        s += d.s + 1ll * c * d.l, c = d.l == n ? c + n : d.r;
      });
      f(rs * B, r);
    }
    return s;
  }
};

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  DS g(a);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      g.set(i, x);
    }
    else {
      INT(l, r, x);
      --l;
      print(g.prod(l, r, x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}