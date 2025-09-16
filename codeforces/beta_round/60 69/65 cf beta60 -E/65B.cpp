#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int pr = 1000;
  FOR(i, N) {
    string s = to_str(a[i]);
    FOR(k, pr, 2012) {
      string t = to_str(k);
      int c = 0;
      FOR(i, 4) c += s[i] != t[i];
      if (c > 1) continue;
      pr = a[i] = k;
      break;
    }
  }
  FOR(i, N) if (not(1000 <= a[i] and a[i] < 2012)) 
    return print("No solution");
  if (a == sorted(a))
    FOR(i, N) print(a[i]);
  else
    print("No solution");
}
#include "YRS/Z_H/main.hpp"