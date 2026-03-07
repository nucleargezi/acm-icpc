#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/heap/merge.hpp"
#include "YRS/ds/un/dsu.hpp"

using heap = merge_heap<pair<ll, int>, 0, 0>;
using np = heap::np;
void Yorisou() {
  LL(T, W, K);
  heap q;
  FOR(T) {
    INT(N, Q);
    vc<np> t(N), e(N);

    Z bina = [&](int i) {
      while (q.size(e[i])) {
        if (q.top(t[i]) == q.top(e[i])) {
          t[i] = q.pop(t[i]), e[i] = q.pop(e[i]);
        } else break;
      }
    };

    dsu g(N);
    VEC(ll, a, N);
    FOR(i, N) t[i] = q.newnode({a[i], -i});
    FOR(Q) {
      INT(op);
      if (op == 2) {
        INT(x);
        --x;
        int f = g[x];
        e[f] = q.push(e[f], {a[x], -x});
        a[x] = 0;
        bina(f);
        t[f] = q.push(t[f], {a[x], -x});
      } else if (op == 3) {
        LL(x, y);
        --x;
        int f = g[x];
        Z [w, id] = q.top(t[f]);
        e[f] = q.push(e[f], {w, id});
        bina(f);
        w = max(0ll, w - y);
        a[-id] = w;
        t[f] = q.push(t[f], {w, id});
      } else {
        INT(x, y);
        if (x == y) continue;
        --x, --y;
        x = g[x], y = g[y];
        g.merge(x, y);
        int f = g[x], th = f ^ x ^ y;
        t[f] = q.merge(t[f], t[th]);
        e[f] = q.merge(e[f], e[th]);
        bina(f);
      }
    }
    
    ll s = 0, max = 0;
    FOR(i, N) if (g[i] == i) {
      ll w = q.top(t[i]).fi;
      chmax(max, w);
      s += w;
    }
    if (W == 2) s -= max;
    if (W == 3) s += max;
    print(s == 0 ? "Gensokyo" : s > K ? "Hell" : "Heaven", s);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"