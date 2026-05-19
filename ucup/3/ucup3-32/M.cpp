#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/ddp_re.hpp"

struct DP {
  struct X {
    int op;
    bool top[2], dn[2];
    int s[2], com[2];
  };

  static X sing(int f) {
    X x {};
    x.op = 0;
    FOR(i, 2) x.top[i] = x.dn[i] = x.s[i] = i ^ f;
    return x;
  }

  static X com(const X &L, const X &R) {
    X c{};
    c.op = 0;
    FOR(i, 2) {
      int cld = L.dn[i], cru = R.top[cld];
      c.top[i] = L.top[i];
      c.dn[i] = R.dn[cld];
      c.s[i] = L.s[i] + R.s[cld] + L.com[cru];
      c.com[i] = R.com[i];
    }
    return c;
  }

  static X com1(const X &L, const X &R) { return com(L, R); }

  static X com2(const X &L, const X &R) {
    X x = L;
    x.com[0] += R.s[0];
    x.com[1] += R.s[1];
    return x;
  }

  static X rak(const X &L, const X &R) {
    X x = L;
    x.s[0] += R.s[0];
    x.s[1] += R.s[1];
    return x;
  }

  static X rak1(const X &L, const X &R) {
    X x = L;
    FOR(p, 2) x.s[p] += R.s[L.top[p]];
    return x;
  }
};
using X = DP::X;
void Yorisou() {
  INT(N, Q);
  VEC(char, a, N);
  FOR(i, N) a[i] -= '0';
  graph g(N);
  g.sc();
  hld v(g);
  Z make = [&](int i) -> pair<X, X> {
    X x = DP::sing(a[i]);
    return {x, x};
  };
  dynamic_tree_dp_re<int, DP> dp(v, make);
  int t = 0;
  FOR(Q) {
    INT(op, i);
    --i;
    if (op == 1) a[i] ^= 1, dp.set(i, make(i));
    if (op == 2) t = i;
    print(dp.prod(t).s[0]);
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}