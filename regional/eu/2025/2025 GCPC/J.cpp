#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  STR(op);
  INT(N);
  STR(s);
  if (sorted(s) == sorted(s, greater())) return print(s);
  if (op == "Encode") {
    int i = N - 1;
    while (s[i] == s[i - 1]) --i;
    FOR(k, i, N) s[k] = '2';
    print(s);
  } else {
    int p = -1;
    FOR(i, N) {
      int k = i == 0 ? N - 1 : i - 1;
      if (s[i] != '2' and s[k] == '2') p = i; 
    }
    int c = 0;
    string ans;
    FOR(i, N) {
      if (s[p] == '0') ans += '0', c = 0;
      else if (s[p] == '1') ans += '1', c = 1;
      else ans += '1' - c;
      p = p + 1 < N ? p + 1 : 0;
    }
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"