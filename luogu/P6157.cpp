#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid.hpp"

// #define tests
struct mono {
  using X = vector<int>;

  static X op(X a, X b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    a.insert(a.end(), all(b));
    unique(a);
    reverse(a);
    while (len(a) > 2) pop(a);
    return a;
  }
  static X unit() { return {}; }
  static X make(int x) { return {x}; }
  constexpr static bool commute = true;
};
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  VEC(int, a, N);
  tree_monoid<decltype(v), mono> seg(
      v, [&](int i) { return mono::make(a[i]); });
  map<int, int> mp;
  FOR(i, N) ++mp[a[i]];
  
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x;
      --mp[a[x]];
      a[x] += y;
      ++mp[a[x]];
      seg.set(x, mono::make(a[x]));
    } else {
      INT(x, y);
      --x, --y;
      Z a = seg.prod_path(x, y);
      if (len(a) == 1) {
        print(-1);
        continue;
      }
      for (int x : a) --mp[x];
      int s = a[1], t = 0;
      bool f = 0;
      for (Z it = mp.rbegin(); it != mp.rend() and t == 0; ++it) {
        if (it->se == 0) continue;
        if (not f) f = true;
        else t = it->fi;
      }
      for (int x : a) ++mp[x];
      print(s, t);
    }
  }
}
#include "YRS/Z_H/main.hpp"