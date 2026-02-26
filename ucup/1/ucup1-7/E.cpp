#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/ptable.hpp"

#define tests 1
#define fl 0
#define DB 10
Z pt = ptable(1'000'00);
vc<u8> is = []() {
  vc<u8> vis(1'000'00 + 10);
  for (int x : pt) vis[x] = 1;
  return vis;
}();
void Yorisou() {
  using std::gcd;
  INT(l, r);
  if (l == 1 and r == 1) return print(1);
  ++r;
  if (r - l == 1) return print(-1);
  if ((r - l) & 1) {
    FOR(i, l, r, 2) {
      if (i + 2 >= r) break;
      int a[3]{i, i + 1, i + 2};
      while (std::next_permutation(a, a + 3)) {
        if (gcd(a[0], i) == 1 and gcd(a[1], i + 1) == 1 and gcd(a[2], i + 2) == 1) {
          vc<int> ans;
          int d = 1;
          FOR(k, l, i) {
            ans.ep(k + d);
            d = -d;
          }
          ans.ep(a[0]);
          ans.ep(a[1]);
          ans.ep(a[2]);
          d = 1;
          FOR(k, i + 3, r) {
            ans.ep(k + d);
            d = -d;
          }
          return print(ans);
        }
      }
    }
    if (l & 1) {
      FOR(i, l, r, 2) if (is[i] or i == 1) {
        if (i != r - 1 and gcd(i, r - 1) == 1) {
          vc<int> res(r - l);
          iota(all(res), l);
          swap(res[i - l], res.back());
          FOR(i, l, r - 1, 2) swap(res[i], res[i + 1]);
          return print(res);
        }
        if (i != l and gcd(i, l) == 1) {
          vc<int> res(r - l);
          iota(all(res), l);
          swap(res[l], res[i]);
          FOR(i, l + 1, r, 2) swap(res[i], res[i + 1]);
          return print(res);
        }
      }
    }
    print(-1);
  } else {
    int d = 1;
    vc<int> ans;
    FOR(i, l, r) {
      ans.ep(i + d);
      d = -d;
    }
    print(ans);
  }
}
#include "YRS/aa/main.hpp"