#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/string/run_length.hpp"

bool ck(const vc<int> &a) {
  int N = len(a);
  int c[3]{};
  FOR(i, N) c[a[i] - 1] += 1;
  if (c[1] != c[2] or QMIN(c, c + 3) == 0) return 0;
  Z seg = run_length(a);
  if (seg.back().fi != 3 or seg.end()[-2].fi != 2) return 0;
  vc<int> b;
  FOR(i, N) if (a[i] != 3) b.ep(a[i] == 1 ? 1 : -1);
  b = pre_sum(b);
  if (QMIN(b) < 0) return 0;
  b.clear();
  FOR(i, N) if (a[i] != 1) b.ep(a[i] == 2 ? 1 : -1);
  b = pre_sum(b);
  return QMIN(b) >= 0;
}

void Yorisou() {
  STR(s);
  int N = len(s);
  vc<int> a(N);
  FOR(i, N) a[i] = s[i] == 'W' ? 1 : s[i] == 'G' ? 2 : 3;
  possible(ck(a));
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"