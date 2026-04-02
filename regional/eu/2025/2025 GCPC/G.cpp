#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  string s = "aA0!!!!!!!!!";
  vector<string> ans;
  for (int i = 0; i < 93 and len(ans) < 1000; ++i) {
    for (int k = 0; k < 93 and len(ans) < 1000; ++k) {
      for (int j = 0; j < 93 and len(ans) < 1000; ++j) {
        for (int l = 0; l < 93 and len(ans) < 1000; ++l) {
          string t = s;
          t[4] += i, t[5] += i;
          t[6] += k, t[7] += k;
          t[8] += j, t[9] += j;
          t[10] += l, t[11] += l;
          ans.ep(t);
        }
      } 
    }
  }
  FOR(i, N) print(ans[i]);
}
#include "YRS/Z_H/main.hpp"