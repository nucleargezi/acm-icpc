#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  S(a, b);
  const int N = len(a);
  string ans;
  FOR(i, N) ans += a[i] == b[i] ? '0' : '1';
  UL(ans);
}
#include "YRS/Z_H/main.hpp"