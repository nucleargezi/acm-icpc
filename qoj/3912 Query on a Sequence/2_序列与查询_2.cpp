#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/spl/splay_mono.hpp"

constexpr int K = 11;
constexpr array<array<uint, K>, K> C = []() {
  array<array<uint, K>, K> C{};
  FOR(i, K) {
    C[i][0] = C[i][i] = 1;
    FOR(k, 1, i) C[i][k] = C[i - 1][k - 1] + C[i - 1][k];
  }
  return C;
}();

struct X {
  uint sz, s[K];

  X() = default;
  
  X(uint x) {
    sz = 1;
    FOR(i, K) s[i] = x;
  }
};

struct MX {
  using X = ::X;

  static X op(const X &a, const X &b) {
    X c{};
    c.sz = a.sz + b.sz;
    uint pw[K];
    pw[0] = 1;
    FOR(i, 1, K) pw[i] = pw[i - 1] * a.sz;
    FOR(i, K) {
      uint rs = a.s[i];
      FOR(k, i + 1) rs += b.s[k] * C[i][k] * pw[i - k];
      c.s[i] = rs;
    }
    return c;
  }
  
  static X unit() { return {}; }
};

using DS = splay_mono<MX>;
using np = DS::np;
void Yorisou() {
  INT(N);
  DS ds;
  VEC(uint, a, N);
  np t = ds.newnode(vc<X>(all(a)));

  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      Z [l, r] = ds.spl(t, i);
      t = ds.me(l, ds.newnode(x), r);
    } else if (op == 2) {
      INT(i);
      Z [l, m, r] = ds.spl(t, i, i + 1);
      t = ds.me(l, r);
    } else if (op == 3) {
      INT(i, x);
      ds.set(t, i, x);
    } else {
      INT(l, r, K);
      ++r;
      print(ds.prod(t, l, r).s[K]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}