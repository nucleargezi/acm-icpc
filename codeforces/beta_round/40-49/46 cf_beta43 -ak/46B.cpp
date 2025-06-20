#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  map<string, int> m;
  vector<string> ts{"S", "M", "L", "XL", "XXL"};
  FOR(i, 5) m[ts[i]] = i;
  VEC(int, c, 5);
  LL(n);
  FOR(n) {
    S(s);
    int x = m[s];
    string ans;
    FOR(i, 5) {
      if (x + i < 5 and c[x + i]) {
        ans = ts[x + i];
        --c[x + i];
        break;
      }
      if (x - i > -1 and c[x - i]) {
        ans = ts[x - i];
        --c[x - i];
        break;
      }
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"