#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
int T = 0;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(M, N, K);
  map<string, array<vector<int>, 3>> mp;
  min_heap<int> q;
  FOR(i, N) q.eb(i);
  FOR(i, M) {
    STR(s);
    if (len(mp[s][2])) continue;
    int r = 0;
    if (len(mp[s][r]) == K - 1) {
      for (int x : mp[s][r]) q.eb(x);
      mp[s][r].clear();
      ++r;
    }
    if (len(mp[s][r]) == K - 1) {
      for (int x : mp[s][r]) q.eb(x);
      mp[s][r].clear();
      ++r;
    }
    if (not q.empty()) {
      mp[s][r].ep(pop(q));
    }
  }
  vector<tuple<int, int, string>> r;
  for (Z &[s, ar] : mp) {
    FOR(i, 3) {
      for (int x : ar[i]) {
        r.ep(x, i, s);
      }
    }
  }
  vector<string> ans(N, "-1");
  for (Z & [ x, r, y ] : r) {
    if (r) y += to_str(r + 1);
    ans[x] = y;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"