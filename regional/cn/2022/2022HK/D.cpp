#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/fib_search.hpp"

#define tests 0
#define fl 0
#define DB 10

bool ccw(PII x, PII y) { return x.fi * y.se - x.se * y.fi <= 0; }
struct convex {
  vc<PII> a;
  convex(int N) { a.reserve(N); }
  PII &operator[](int i) { return a[i]; }

  void add(PII x) {
    if (not a.empty() and a.back().se <= x.se) return;
    while (len(a) > 1) {
      PII i = a.end()[-2], k = a.end()[-1];
      k = {k.fi - i.fi, k.se - i.se};
      i = {x.fi - i.fi, x.se - i.se};
      if (ccw(k, i)) a.pop_back();
      else break;
    }
    a.ep(x);
  }
};
void Yorisou() {
  INT(N, M);
  vvc<int> v(N);
  FOR(M) {
    INT(x, y, c);
    --x, --y;
    v[x].ep(y << 1 | c);
  }

  INT(Q);
  vc<int> ans(Q);
  vvc<T3<int>> qs(N);
  FOR(i, Q) {
    INT(a, b, t);
    --t;
    qs[t].ep(a, b, i);
  }

  convex t(N);
  Z merge = [&](convex &a, convex &b) {
    t.a.clear();
    int i = 0, k = 0, N = len(a.a), M = len(b.a);
    for (; i < N and k < M;) {
      if (a[i].fi != b[k].fi) {
        if (a[i].fi < b[k].fi) t.add(a[i++]);
        else t.add(b[k++]);
      } else {
        t.add(min(a[i], b[k]));
        ++i, ++k;
      }
    }
    for (; i < N; ++i) t.add(a[i]);
    for (; k < M; ++k) t.add(b[k]);
    b.a.resize(len(t.a));
    copy(all(t.a), b.a.begin());
  };
  
  vc<convex> hull(1001, convex(N));
  hull[0].add({0, 0});
  FOR(n, N) {
    int p = n % 1001;
    for (Z [a, b, i] : qs[n]) {
      ans[i] = fib_search<int, true, int>([&](int i) {
        return a * hull[p][i].fi + b * hull[p][i].se;
      }, 0, len(hull[p].a)).fi;
    }
    for (int e : v[n]) {
      int x = e >> 1, c = e & 1;
      for (PII &x : hull[p].a) ++(c ? x.se : x.fi);
      merge(hull[p], hull[x % 1001]);
      for (PII &x : hull[p].a) --(c ? x.se : x.fi);
    }
    hull[p].a.clear();
  }
  FOR(i, Q) print(ans[i]);
}
#include "YRS/aa/main.hpp"