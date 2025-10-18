#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SAM.hpp"

// #define tests
void Yorisou() {
  STR(s);
  const int N = len(s);
  FOR(i, N) s[i] -= 'a';
  sam seg(N << 1);
  ll ans = 0;
  vector<int> sz = seg.build(s);
  const int M = len(seg);
  FOR(i, 1, M) if (sz[i] > 1) chmax(ans, 1ll * sz[i] * seg[i].sz);
  print(ans);
}
#include "YRS/Z_H/main.hpp"