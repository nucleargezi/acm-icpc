#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/ddp.hpp"

struct X {
  int a, b, s, sz;
};
struct DP {
  using X = ::X;

  static X com(var a, var b) {
    X rs = a;
    if (b.a != -1) chmax(rs.a, b.a + a.sz);
    if (a.b != -1) chmax(rs.b, a.b + b.sz);
    chmax(rs.b, b.b);
    rs.sz += b.sz;
    chmax(rs.s, b.s);
    if (a.b != -1 and b.a != -1) chmax(rs.s, a.b + b.a);
    return rs;
  }

  static X rak(var a, var b) {
    X rs = a;
    chmax(rs.a, b.a);
    if (b.a != -1) chmax(rs.b, a.sz + b.a);
    chmax(rs.s, b.s);
    if (a.a != -1 and b.a != -1) chmax(rs.s, a.a + b.a);
    return rs;
  }
};

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }

  vc<char> vis(N, 1);
  Z sing = [&](int i) -> X {
    X rs{!!i, 0, -1, !!i};
    if (not vis[i]) rs.a = rs.b = -1;
    return rs;
  };
  hld v(g, 0);
  ddp<int, DP> dp(v, sing);
  INT(Q);
  FOR(Q) {
    INT(x);
    --x;
    vis[x] ^= 1;
    dp.set(x, sing(x));
    print(dp.prod().s);
  }
}

int main() {
  Yorisou();
  return 0;
}