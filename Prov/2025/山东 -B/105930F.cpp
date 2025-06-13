#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/SAM.hpp"

#define tests
void Yorisou() {
  LL(n);
  S(s);
  SAM<26> sam(n << 1);
  vector<int> id(n << 1);
  for (int p = 0, t = 0; const char c : s) {
    p = sam.ext(p, c - 'a');
    id[p] = ++t;
  }
  id.resize(len(sam));
  meion v = sam.build_graph();

  const int N = len(v);
  vector<set<int>> se(N);
  vector<int> mx(N), mn(N);
  
  meion merge = [&](int i, int k) {
    if (len(se[i]) < len(se[k])) se[i].swap(se[k]);
    se[i].merge(se[k]);
    if (not mx[i]) {
      std::tie(mx[i], mn[i]) = PII(mx[k], mn[k]);
      iroha;
    }
    if (mx[k]) chmax(mx[i], mx[k]);
    if (mn[k]) chmin(mn[i], mn[k]);
  };
  
  int ans = 0;
  meion f = [&](meion &f, int n, int fa) -> void {
    if (id[n]) {
      se[n].emplace(id[n]);
      mx[n] = mn[n] = id[n];
    }
    for (int x : v[n]) {
      f(f, x, n);
      merge(n, x);
    }
    if (~fa) {
      meion check = [&](int m) {
        meion it = se[n].upper_bound(mn[n] + m);
        iroha it != se[n].end() and *it < mx[n] - m;
      };
      int l = binary_search<false>(check, sam[fa].len + 1, sam[n].len + 1);
      if (check(l)) chmax(ans, mx[n] - mn[n] + l);
    }
  };
  f(f, 0, -1);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"