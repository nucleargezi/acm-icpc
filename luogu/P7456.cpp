#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/min.hpp"

#define tests 0
#define fl 0
#define DB 10
struct AC {
  struct node {
    int sz, fa, mx;
    array<int, 26> next;
    node() : sz(0), fa(0), mx(0), next{} {}
    int &operator[](int i) { return next[i]; }
  };
  vc<node> a;
  vc<int> sz;

  AC() : a(1), sz(1) {}

  int newnode() {
    a.ep();
    sz.ep(0);
    return len(a) - 1;
  }

  int add(const string &s) {
    int t = 0;
    for (char x : s) {
      if (a[t][x] == 0) {
        a[t][x] = newnode();
        a[a[t][x]].sz = a[t].sz + 1;
      }
      t = a[t][x];
    }
    ++sz[t];
    chmax(a[t].mx, len(s));
    return t;
  }

  vc<int> build(const string &s) {
    queue<int> q;
    FOR(i, 26) if (a[0][i]) q.eb(a[0][i]);
    while (not q.empty()) {
      int x = q.pop();
      chmax(a[x].mx, a[a[x].fa].mx);
      FOR(i, 26) {
        if (a[x][i] == 0) {
          a[x][i] = a[a[x].fa][i];
        } else {
          a[a[x][i]].fa = a[a[x].fa][i];
          q.eb(a[x][i]);
        }
      }
      sz[x] += sz[a[x].fa];
    }
    int sz = len(s);
    vc<int> r(sz, 0);
    int t = 0;
    FOR(i, sz) {
      int x = s[i] - 'a';
      t = a[t][x];
      r[i] = a[t].mx;
    }
    return r;
  }
};
void Yorisou() {
  INT(N);
  STR(s);
  AC ac;
  FOR(N) {
    STR(s);
    for (Z &c : s) c -= 'a';
    ac.add(s);
  }

  N = len(s);
  vc<int> f = ac.build(s);
  Seg<monoid_min<int>> dp(N);
  FOR(i, N) {
    if (f[i] > 0) {
      int d = f[i];
      if (d > i) dp.set(i, 1);
      else {
        int x = dp.prod(max(i - d, 0), i);
        if (x != inf<int>) dp.set(i, x + 1);
      }
    }
  }
  int ans = dp.get(N - 1);
  print(ans > N ? -1 : ans);
}
#include "YRS/aa/main.hpp"