#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/ddp.hpp"

struct X {
  ll a[2]{}, b{};
  int c{};
  bool ab{}, sp{};
  ll s{};
  int sc{};
  bool sa{}, sb{};
};

struct DP {
  using X = ::X;

  static X com(const X &a, const X &b) {
    X c;
    c.c = b.c;
    FOR(i, 2) {
      c.a[i] = a.a[i];
      if (a.ab and a.c == i) c.a[i] += b.a[i];
    }
    if (b.ab and b.c == a.c) {
      c.b = a.b + b.a[b.c];
      c.ab = a.ab;
    } else {
      c.b = b.b;
      c.ab = 0;
    }
    if (a.sp) {
      c.sp = 1;
      c.s = a.s;
      c.sc = a.sc;
      c.sa = a.sa;
      if (a.sb) {
        c.s += b.a[a.sc];
        c.sb = b.ab and b.c == a.sc;
      } else {
        c.sb = 0;
      }
    } else if (b.sp) {
      c.sp = 1;
      c.sc = b.sc;
      if (b.sa and b.sc == a.c) {
        c.s = a.b + b.a[b.sc];
        c.sa = a.ab;
        c.sb = b.ab and b.c == b.sc;
      } else {
        c.s = b.s;
        c.sa = 0;
        c.sb = b.sb;
      }
    }
    return c;
  }

  static X rak(const X &a, const X &b) {
    X c;
    c.a[0] = a.a[0] + b.a[0];
    c.a[1] = a.a[1] + b.a[1];
    c.b = a.b;
    c.c = a.c;
    c.ab = a.ab;
    if (a.sp) {
      c.sp = 1;
      c.s = a.s;
      c.sc = a.sc;
      c.sa = a.sa;
      c.sb = a.sb;
    } else if (b.sp) {
      c.sp = 1;
      c.s = b.s;
      c.sc = b.sc;
      c.sa = b.sa;
      c.sb = 0;
    }
    return c;
  }
};

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> g(N);
  VEC(ll, w, N);
  VEC(int, c, N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }

  vc<u8> vis(N, 0);
  Z sing = [&](int i) {
    X x;
    x.c = c[i];
    x.b = w[i];
    x.ab = 1;
    x.a[c[i]] = w[i];
    if (vis[i]) {
      x.sp = x.sa = x.sb = 1;
      x.s = w[i];
      x.sc = c[i];
    }
    return x;
  };
  hld<int> v(g, 0);
  ddp<int, DP> dp(v, sing);

  int t = -1;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x);
      --x;
      c[x] ^= 1;
      dp.set(x, sing(x));
    } else if (op == 2) {
      INT(x);
      LL(y);
      --x;
      w[x] += y;
      dp.set(x, sing(x));
    } else {
      INT(x);
      --x;
      if (t != -1 and t != x) vis[t] = 0, dp.set(t, sing(t));
      t = x;
      if (not vis[t]) vis[t] = 1, dp.set(t, sing(t));
      print(dp.prod().s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}