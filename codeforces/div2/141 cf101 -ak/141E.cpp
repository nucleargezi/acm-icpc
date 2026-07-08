#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/al/m/maxidx.hpp"
#include "YRS/ds/un/dsu.hpp"

using MX = Maxidx<int>;
using DS = lct_mono<MX>;
void Yorisou() {
  INT(N, M);
  vc<T3<int>> es(M);
  FOR(i, M) {
    INT(a, b);
    CH(c);
    --a, --b;
    es[i] = {a, b, c == 'S'};
  }
  
  dsu g(N);
  vc<char> vis(M);
  DS lct(N + M);
  FOR(i, N) lct[i]->mx = {0, i};
  FOR(i, M) lct[i + N]->mx = {0, i};
  int A[2]{};
  vc<int> ls[2], rs[2];
  FOR(i, M) {
    var [a, b, op] = es[i];
    if (g.merge(a, b)) {
      vis[i] = 1;
      ++A[op];
      ls[op].ep(i);
    } else {
      rs[op].ep(i);
    }
  }
  if (g.c != 1) return print(-1);
  if (A[0] < A[1]) swap(ls[0], ls[1]), swap(rs[0], rs[1]);

  for (int i : ls[0]) {
    var [a, b, _] = es[i];
    lct[i + N]->mx.fi = 1;
    lct.link(a, i + N);
    lct.link(b, i + N);
  }
  for (int i : ls[1]) {
    var [a, b, _] = es[i];
    lct.link(a, i + N);
    lct.link(b, i + N);
  }
  int d = abs(A[0] - A[1]);
  if (d & 1) return print(-1);
  d >>= 1;
  
  for (int i : rs[1]) if (d) {
    var [a, b, _] = es[i];
    Z [ok, id] = lct.prod(a, b);
    if (ok) {
      var [f, t, _] = es[id];
      vis[id] = 0;
      lct.cut(f, id + N);
      lct.cut(t, id + N);
      lct.link(i + N, a);
      lct.link(i + N, b);
      vis[i] = 1;
      --d;
    }
  }
  if (d) return print(-1);
  vc<int> s;
  FOR(i, M) if (vis[i]) s.ep(i + 1);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}