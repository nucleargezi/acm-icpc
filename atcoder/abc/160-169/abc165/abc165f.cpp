#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segd.hpp"

struct MX {
  using X = int;
  static X unit() { return 0; }
  static X op(X a, X b) { return max(a, b); }
  static constexpr bool commute = 1;
}; 

using DS = segd<MX, 1>;
using np = DS::np;

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  
  DS seg(0, N);
  vc<np> t(N);
  vc<char> in(N);
  vc<int> q{0};
  in[0] = 1;
  FOR(i, N) {
    int n = q[i], x = a[n];
    t[n] = seg.set(t[n], x, seg.prod(t[n], 0, x) + 1);
    for (int x : g[n]) if (not in[x]) {
      in[x] = 1, q.ep(x), t[x] = t[n];
    }
  }
  FOR(i, N) print(seg.prod(t[i]));
}

int main() { Yorisou(); }