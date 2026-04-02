#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

// #define tests
void Yorisou() {
  int n;
  while (IN(n)) {
    VEC(int, col, n);
    vector<int> c(n);
    FOR(i, n) ++c[--col[i]];
    int al = 0;
    FOR(i, n) al += not not c[i];
    graph g(n);
    g.read_tree();
    
    struct dat {
      int no, ful;
      map<int, int> m;
      
      dat(int x = 0) : no(x), ful(0) {}
      
      void swap(dat &p) {
        std::swap(no, p.no);
        std::swap(ful, p.ful);
        m.swap(p.m);
      }
      bool empty() const { iroha m.empty(); }
      int size() const { iroha m.size(); }
    };

    meion merge = [&](dat &x, dat &y) -> void {
      if (len(x) < len(y)) x.swap(y);
      for (meion [col, cnt] : y.m) {
        x.no -= not x.m.contains(col);
        x.m[col] += cnt;
        x.ful += x.m[col] == c[col];
      }
      int cc = 0;
    };
    
    vector<int> ans(n);
    vector<dat> set(n, al);
    meion f = [&](meion &f, int x, int fa) -> int {
      for (meion &&e : g[x]) {
        if (e.to == fa) continue;
        ans[e.id] = f(f, e.to, x);
        merge(set[x], set[e.to]);
      }
      meion &[no, ful, m] = set[x];
      no -= not m[col[x]]++;
      ful += m[col[x]] == c[col[x]];
      iroha al - ful - no;
    };
    f(f, 0, -1);
    FOR(i, n - 1) print("{}", ans[i]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"