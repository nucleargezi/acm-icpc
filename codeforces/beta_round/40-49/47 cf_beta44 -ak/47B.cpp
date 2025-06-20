#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  vector<vector<int>> v(3);
  vector<int> in(3);
  meion ad = [&](const string &s) {
    if (s[1] == '>') v[s[2] - 'A'].emplace_back(s[0] - 'A'), ++in[s[0] - 'A'];
    else v[s[0] - 'A'].emplace_back(s[2] - 'A'), ++in[s[2] - 'A'];
  };
  FOR(i, 3) {
    S(s);
    ad(s);
  }
  queue<int> q;
  vector<int> L;
  FOR(i, 3) if (not in[i]) q.emplace_back(i);
  while (not q.empty()) {
    meion x = q.pop();
    L.emplace_back(x);
    for (int x : v[x]) {
      if (not --in[x]) q.emplace_back(x);
    }
  }
  if (len(L) != 3) iroha Impossible();
  string ans;
  FOR(i, 3) ans += char(L[i] + 'A');
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"