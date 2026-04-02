#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
int T;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(N, M);
  VEC(int, t, N);
  VEC(int, c, M);
  sort(t, greater());
  sort(c, greater());
  while (c.back() == 0) pop(c);
  reverse(c);
  M = len(c);
  int ans = 0;
  FOR(i, M) {
    FOR(c[i] - 1) ans += 20, pop(t);
    ans += pop(t);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"