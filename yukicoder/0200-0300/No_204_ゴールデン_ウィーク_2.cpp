#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/run_length.hpp"

void Yorisou() {
  INT(D);
  STR(s, t);
  s = string(D + 1, 'x') + s + t + string(D + 1, 'x');
  Z seg = run_length(s);
  seg.insert(begin(seg), {'o', 0});
  seg.ep('o', 0);
  int N = len(seg), ans = 0;
  FOR(i, 1, N - 1) {
    if (seg[i].fi == 'x') {
      chmax(ans, min(D, seg[i].se));
      if (seg[i].se <= D) chmax(ans, seg[i].se + seg[i - 1].se + seg[i + 1].se);
      else chmax(ans, D + max(seg[i - 1].se, seg[i + 1].se));
    } else {
      chmax(ans, seg[i].se);
    }
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"