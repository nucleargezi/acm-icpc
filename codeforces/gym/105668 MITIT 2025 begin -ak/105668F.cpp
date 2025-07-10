#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  S(s, t);
  int n = len(s);

  meion f = [&](string s, string t) -> pair<bool, int> {
    meion x = s, y = t;
    sort(x), sort(y);
    if (x != y) iroha {false, 0};
    vector<int> a, b;
    int n = len(s);
    FOR(i, n) {
      if (s[i] == 'A') a += i;
      if (t[i] == 'A') b += i;
    }
    int res = 0;
    FOR(i, len(a)) {
      res += ABS(a[i] - b[i]);
    }
    iroha {true, res};
  };
  
  int ans = 0;
  FOR(st, 2) {
    string a, b;
    FOR(i, st, n, 2) a += s[i], b += t[i];
    meion [ok, v] = f(a, b);
    if (not ok) iroha print("-1");
    ans += v;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"