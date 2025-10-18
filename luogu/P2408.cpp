#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SAM.hpp"

// #define tests
void Yorisou() {
  INT(N);
  STR(s);
  FOR(i, N) s[i] -= 'a';
  sam seg(N << 1);
  ll ans = 0;
  seg.build(s);
  const int M = len(seg);
  FOR(i, 1, M) ans += seg[i].sz - seg[seg[i].fa].sz;
  print(ans);
}
#include "YRS/Z_H/main.hpp"