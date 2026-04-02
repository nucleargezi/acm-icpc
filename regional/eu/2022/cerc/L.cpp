#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  VEC(int, a, 98);
  reverse(a);
  vc<int> q;
  FOR(8) q.ep(pop(a));
  vc<int> st[4];
  st[0] = st[1] = {1};
  st[2] = st[3] = {100};
  while (not q.empty()) {
    int cnt = 2;
    while (cnt) {
      vc<PII> bst;
      FOR(i, len(q)) {
        int x = q[i];
        FOR(k, 2) {
          if (st[k].back() - x == 10) bst.ep(i, k);
        }
        FOR(k, 2, 4) {
          if (x - st[k].back() == 10) bst.ep(i, k);
        }
      }
      if (not bst.empty()) {
        --cnt;
        Z [i, k] = bst[0];
        st[k].ep(q[i]);
        q.erase(bg(q) + i);
        continue;
      }
      int mx = inf<int>, ii = -1, kk;
      FOR(i, len(q)) {
        int x = q[i];
        FOR(k, 2) {
          if (st[k].back() < x and chmin(mx, x - st[k].back())) ii = i, kk = k;
        }
        FOR(k, 2, 4) {
          if (st[k].back() > x and chmin(mx, st[k].back() - x)) ii = i, kk = k;
        }
      }
      if (mx == inf<int>) break;
      st[kk].ep(q[ii]);
      q.erase(bg(q) + ii);
      --cnt;
    }
    if (cnt) break;
    FOR(2) if (not a.empty()) q.ep(pop(a));
  }
  reverse(a);
  FOR(i, 4) print(st[i]);
  print(q);
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"