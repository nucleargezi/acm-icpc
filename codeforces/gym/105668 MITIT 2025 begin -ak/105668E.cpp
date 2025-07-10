#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  vector<set<int>> se(n);
  FOR(i, n) se[a[i]].emplace(i);
  set<int> ok;
  FOR(i, n) if (se[i].empty()) {
    ok.emplace(i);
  }
  FOR(q) {
    INT(op, x, y);
    --x, --y;
    if (op == 1) {
      se[a[x]].extract(x);
      if (se[a[x]].empty()) ok.emplace(a[x]);
      a[x] = y;
      if (se[a[x]].empty()) ok.extract(a[x]);
      se[a[x]].emplace(x);
    } else {
      int ans = ok.empty() ? x ? a[x - 1] : a[y + 1] : *ok.begin();
      print("{}", ans + 1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"