#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
using T = tuple<string, int, int>;
void Yorisou() {
  INT(N);
  VEC(T, a, N);
  int cnt = 0;
  string ans;
  FOR(i, 123, 10000) {
    string s = to_str(i);
    while (len(s) < 4) s = "0" + s;
    string ss = s;
    sort(ss);
    if (ss[0] == ss[1] or ss[1] == ss[2] or ss[2] == ss[3]) continue;
    bool ok = 1;
    for (int i = 0; i < N and ok; ++i) {
      meion [t, x, y] = a[i];
      int xx = 0, yy = 0;
      FOR(i, 4) {
        xx += s[i] == t[i];
        bool f = 0;
        FOR(k, 4) f |= s[i] == t[k];
        yy += f;
      }
      ok &= x == xx and y == yy - xx;
    }
    if (ok) ++cnt, ans = s;
  }
  if (not cnt) UL("Incorrect data");
  else if (cnt > 1) UL("Need more data");
  else UL(ans);
}
#include "YRS/Z_H/main.hpp"