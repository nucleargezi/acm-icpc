#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/string_cmp.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(string, s, N);
  string al;
  vector<int> of{0};
  for (Z &s : s) {
    al += s;
    of.ep(len(al));
  }
  string_cmp seg(al);
  vector<int> I(N);
  iota(all(I), 0);
  sort(I, [&](int i, int k) -> bool {
    return seg.cmp_list({{of[i], of[i + 1]}, {of[k], of[k + 1]}},
               {{of[k], of[k + 1]}, {of[i], of[i + 1]}}) == -1;
  });
  
  vector<int> lcp(N - 1);
  FOR(i, N - 1) {
    int x = I[i], y = I[i + 1];
    lcp[i] = seg.lcp_list({{of[x], of[x + 1]}, {of[y], of[y + 1]}}, 
                          {{of[y], of[y + 1]}, {of[x], of[x + 1]}});
    if (lcp[i] == len(s[x]) + len(s[y])) lcp[i] = inf<int>;
  }
  dsu g(N);
  map<int, vector<int>> mp;
  FOR(i, N - 1) mp[-lcp[i]].ep(i);
  vector<int> lst(N, -inf<int>);
  vector<ll> dat(N);
  ll ans = 0;
  for (Z &[sz, v] : mp) {
    for (int i : v) {
      int x = g[i], y = g[i + 1];
      if (lst[x] == sz and sz != -inf<int>) ans += dat[x] * g.size(y);
      lst[x] = sz;
      dat[x] = 1ll * g.size(x) * g.size(y);
      g.set(x, y);
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"