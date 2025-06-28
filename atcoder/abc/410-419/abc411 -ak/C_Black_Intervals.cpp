#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  set<int> se;
  vector<u8> vis(n + 1);
  FOR(q) {
    LL(x);
    vis[x] ^= 1;
    bool l = (x > 1) and vis[x - 1], r = (x < n) and vis[x + 1];
    if (vis[x]) {
      if (not l and not r) {
        se.emplace(x);
      } else if (l and not r) {
        ;
      } else if (not l and r) {
        se.extract(x + 1);
        se.emplace(x);
      } else {
        se.extract(x + 1);
      }
    } else {
      if (not l and not r) {
        se.extract(x);
      } else if (l and not r) {
        ;
      } else if (not l and r) {
        se.extract(x);
        se.emplace(x + 1);
      } else {
        se.emplace(x + 1);
      }
    }
    UL(len(se));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"