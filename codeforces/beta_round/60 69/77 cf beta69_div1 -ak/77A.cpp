#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  map<string, int> go;
  go["Anka"] = 0;
  go["Chapay"] = 1;
  go["Cleo"] = 2;
  go["Troll"] = 3;
  go["Dracul"] = 4;
  go["Snowy"] = 5;
  go["Hexadecimal"] = 6;
  set<PII> se;
  INT(N);
  FOR(N) {
    string s, t;
    IN(s, t, t);
    se.eb(go[s], go[t]);
  }
 
  INT(a, b, c);
  vector<int> I(7);
  iota(all(I), 0);
  int ans = inf<int>, s = 0;
  do {
    FOR(x, 1, 6) FOR(y, 1, 7 - x) {
      int z = 7 - x - y;
      int mx = std::max({floor(a, x), floor(b, y), floor(c, z)});
      int mn = std::min({floor(a, x), floor(b, y), floor(c, z)});
      int sc = 0;
      FOR(i, x) FOR(k, i + 1, x) {
        int p = i + 0, q = k + 0;
        sc += se.contains({I[p], I[q]});
        sc += se.contains({I[q], I[p]});
      }
      FOR(i, y) FOR(k, i + 1, y) {
        int p = i + x, q = k + x;
        sc += se.contains({I[p], I[q]});
        sc += se.contains({I[q], I[p]});
      }
      FOR(i, z) FOR(k, i + 1, z) {
        int p = i + x + y, q = k + x + y;
        sc += se.contains({I[p], I[q]});
        sc += se.contains({I[q], I[p]});
      }
      if (chmin(ans, mx - mn)) s = sc;
      if (ans == mx - mn) chmax(s, sc);
    }
  } while (std::next_permutation(all(I)));
  print(ans, s);
}
#include "YRS/Z_H/main.hpp"