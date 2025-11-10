#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_act.hpp"

// #define tests
using X = int;
struct MX {
  using X = int;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
using A = int;
struct MA {
  using X = int;
  static constexpr X op(X a, X b) { return b == -1 ? a : b; }
  static constexpr X unit() { return -1; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int sz) { return a == -1 ? x : a * sz; }
};
void Yorisou() {
  INT(N, M);
  VEC(PII, e, M);
  hash_map<int> mp;
  vector<char> vis(M, 1);
  for (int t = 0; Z &[x, y] : e) {
    --x, --y;
    if (x > y) swap(x, y);
    mp[ull(x) << 30 | y] = t++;
  }
  vector<T3<int>> quis;
  while (1) {
    INT(op);
    if (op == -1) break;
    INT(x, y);
    --x, --y;
    if (op == 0) {
      if (x > y) swap(x, y);
      int i = mp[ull(x) << 30 | y];
      vis[i] = 0;
    }
    quis.ep(op, x, y);
  }
  reverse(quis);
  LCT_act_commute<AM> lct(N << 1);
  FOR(i, N, N << 1) lct.a[i].mx = 1;
  int t = N;
  FOR(i, M) if (vis[i]) {
    Z [x, y] = e[i];
    if (lct.get_rt(x) == lct.get_rt(y)) lct.apply(x, y, 0);
    else lct.link(t, x), lct.link(t++, y);
  }
  vector<int> ans;
  for (Z [op, x, y] : quis) {
    if (op == 0) {
      if (lct.get_rt(x) == lct.get_rt(y)) lct.apply(x, y, 0);
      else lct.link(t, x), lct.link(t++, y);
    } else {
      ans.ep(lct.prod(x, y));
    }
  }
  for (reverse(ans); int x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"