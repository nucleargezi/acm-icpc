#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  vector<int> ans;
  vector<int> a(n);
  FOR(i, n) a[i] = i + 1;
  set<int> se{a.begin(), a.end()};
  while (not se.empty()) {
    meion x = *se.begin();
    int y = x;
    while (se.contains(y)) {
      se -= y;
      ans += y;
      y += k;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"