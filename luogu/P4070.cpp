#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SAM_umap.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, s, N);
  ll ans = 0;
  sam seg(N << 1);
  int p = 0;
  FOR(i, N) {
    p = seg.add(p, s[i]);
    ans += seg[p].sz - seg[seg[p].fa].sz;
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"