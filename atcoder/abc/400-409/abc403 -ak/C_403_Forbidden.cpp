#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, q);
  vector<u8> vis(n);
  vector<set<ll>> se(n);
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x, y);
      se[--x] += --y;
    } else if (op == 2) {
      LL(x);
      vis[--x] = 1;
    } else {
      LL(x, y);
      --x, --y;
      Yes(vis[x] or se[x].contains(y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"