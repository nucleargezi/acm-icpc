#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/lct/lct_sayo.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/al/am/sum_add.hpp"

using MX = Add<ll>;
using SY = Sum_add<int>;
void Yorisou() {
  INT(N);
  hashmap<int> mp(N << 1);
  lct_mono<MX> lct(N + N - 1);
  lct_sayo<SY> vis(N);
  FOR(t, N, N + N - 1) {
    INT(a, b, c);
    if (a > b) swap(a, b);
    mp[ll(a) << 32 | b] = t;
    lct[t]->mx = c;
    lct.link(a, t);
    lct.link(b, t);
    vis.link(a, b);
  }
  
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b, c, w);
      int m = b;
      if (a > b) swap(a, b);
      int t = mp[ll(a) << 32 | b];
      lct.cut(a, t);
      lct.cut(b, t);
      vis.cut(a, b);
      lct[t]->mx = w;
      b = m;
      if (b > c) swap(b, c);
      mp[ll(b) << c] = t;
      lct.link(b, t);
      lct.link(c, t);
      vis.link(b, c);
    } else {
      INT(sz);
      VEC(int, vs, sz);
      ll rs = 0;
      static vc<PII> go;
      go.clear();
      for (int t = pop(vs); int x : vs) {
        int g = vis.max_path([&](int s) { return not s; }, x, t);
        if (g == -1) continue;
        if (g == t) {
          rs += lct.prod(x, t);
          vis.apply(x, t, 1);
          go.ep(x, t);
        } else {
          vis.evert(t);
          g = vis.get_fa(g);
          rs += lct.prod(x, g);
          vis.apply(x, g, 1);
          go.ep(x, g);
        }
      }
      for (var [a, b] : go) vis.apply(a, b, -1);
      print(rs);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}