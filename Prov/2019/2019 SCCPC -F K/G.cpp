#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/lpf_table.hpp"

#define tests
int T;
vector<int> mp = lpf_table(1'000'000);
bool ck(int x, int y, int K) {
  while (x > K and y > K) {
    if (mp[x] == x and mp[y] == y) return true;
    --x, --y;
  }
  return false;
}
bool f(int x, int y, int K) {
  if (x == K or y == K) return 1;
  if (mp[x] == x and mp[y] == y) return 0;
  if (not((x + y) & 1)) return 1;
  return not(ck(x - 1, y, K) or ck(x, y - 1, K));
}
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(x, y, K, w);
  if (x == K or y == K) return Bob();
  if (mp[x] == x and mp[y] == y) return Alice();
  Bob(w ? (f(x - 1, y, K) or f(x, y - 1, K)) : f(x, y, K));
}
#include "YRS/Z_H/main.hpp"