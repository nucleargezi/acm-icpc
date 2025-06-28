#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  vector<vector<tuple<int, int, int, string>>> go(n);
  int lp, lt = -1;
  FOR(i, n) go[i].emplace_back(1, 0, lp, "");
  FOR(i, q) {
    LL(op, x);
    --x;
    if (op == 1) {
      go[x].emplace_back(1, lt, lp, "");
    } else if (op == 2) {
      S(str);
      go[x].emplace_back(2, i, x, str);
    } else {
      lp = x, lt = i;
    }
  }
  vector<string> res;
  while (lp != -1 and lt != -1) {
    while (len(go[lp])) {
      meion [op, tim, p, str] = pop(go[lp]);
      if (tim > lt) continue;
      lt = tim;
      if (op == 1) {
        lp = p;
        break;
      } else if (op == 2) {
        res += str;
      }
    }
  }
  string ans;
  for (meion &&s : std::views::reverse(res)) ans += s;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"