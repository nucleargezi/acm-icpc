#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr int B = 1000;
struct DS {
  int N, c0;
  vc<int> a, cnt, val;
  int mn, mx;
  dsu g;

  void build(const vc<int> &v) {
    N = len(v);
    a.resize(N);
    copy(all(v), a.begin());
    c0 = std::count(all(a), -1);
    mn = 0, mx = QMAX(a);
    g.build(mx + 1);
    cnt.assign(mx + 1, 0);
    val.assign(mx + 1, 0);
    for (int x : a) if (x != -1) ++cnt[x];
    FOR(i, mx + 1) val[i] = i;
  }
  
  void upd(int l, int r, int x) {
    if (r - l != N) {
      FOR(i, l, r) if (a[i] != -1) {
        --cnt[g[a[i]]];
        int w = val[g[a[i]]] - mn;
        if (w >= x) w -= x;
        a[i] = w + mn;
        ++cnt[g[a[i]]];
      }
    } else {
      if (not x or mx - mn < x) return;
      int tp = mn + x;
      if (tp - mn >= mx - tp + 1) {
        FOR(i, tp, mx + 1) {
          int to = i - x;
          int X = g[i], Y = g[to];
          g.merge(X, Y);
          int fa = g[X];
          cnt[fa] = cnt[X] + cnt[Y];
          val[fa] = val[Y];
        }
        mx = tp - 1;
      } else {
        FOR(i, mn, tp) {
          int to = i + x;
          int X = g[i], Y = g[to];
          g.merge(X, Y);
          int fa = g[X];
          cnt[fa] = cnt[X] + cnt[Y];
          val[fa] = val[Y];
        }
        mn = tp;
      }
    }
  }

  int f(int l, int r, int x) {
    if (r - l != N) {
      int s = 0;
      if (x == -1) FOR(i, l, r) s += a[i] == -1;
      else FOR(i, l, r) if (a[i] != -1) s += val[g[a[i]]] == x + mn;
      return s;
    } else {
      int rm = mn + x;
      return x == -1 ? c0 : rm > mx ? 0 : cnt[g[rm]];
    }
  }
};
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(i, N) a[i] -= 1;
  int bsz = ceil(N, B);
  int q = 0;
  vc<T4<int>> ops(Q);
  for (Z &[op, l, r, x] : ops) {
    IN(op, l, r, x);
    --l, --r;
    if (op == 1) op = -1;
    else op = q++, --x;
  }
  vc<int> ans(q);
  DS g;
  FOR(i, bsz) {
    g.build({a.begin() + i * B, a.begin() + min(i * B + B, N)});
    for (Z [op, l, r, x] : ops) {
      chmin(r, i * B + B - 1);
      chmax(l, i * B);
      if (l > r) continue;
      l %= B;
      r %= B;
      if (op == -1) {
        g.upd(l, r + 1, x);
      } else {
        ans[op] += g.f(l, r + 1, x);
      }
    }
  }
  FOR(i, q) print(ans[i]);
}
#include "YRS/aa/main.hpp"