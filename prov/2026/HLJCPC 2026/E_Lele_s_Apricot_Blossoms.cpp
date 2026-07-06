#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/near_kinbo.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  hld v(g, 0);
  near_kinbo ds(g, v);
  vc<char> vis(N);
  bit_t<Add<int>> bit(si(ds));

  Z q = [&](int x, int r) {
    int s = 0;
    ds.range(x, 0, r + 1, [&](int l, int r) { s += bit.prod(l, r); });
    return s;
  };

  int t = 0;
  FOR(Q) {
    INT(op, x);
    --x;
    if (op == 1) {
      int w = vis[x] ? -1 : 1;
      ds.vs(x, [&](int i) { bit.add(i, w); });
      vis[x] ^= 1;
    } else {
      t = x;
    }
    if (vis[t]) {
      print(0);
    } else if (q(t, N) == 0) {
      print("2147483648");
    } else {
      print(bina([&](int d) { return q(t, d) > 0; }, N, 0));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}