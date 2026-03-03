#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/wave/wave_mat_sim.hpp"

constexpr uint mask = 0x5f3759dfu;
uint s, ls, op, l, r;
int N, Q;
inline uint rng() {
	s ^= ls ^ mask;
	s ^= s << 13;
	s ^= s >> 7;
	s ^= s << 17;
	s ^= ls ^ mask;
	return s;
}
void Yorisou() {
  IN(N, Q, s);
  vc<uint> a(N);
  FOR(i, N) a[i] = rng();
  wave_mat_sim<uint> ds(a);
  uint ans = 0;
  FOR(Q) {
    op = rng() & 1, l = rng() % N, r = rng() % N;
    if (l > r) swap(l, r);
    ++r;
    if (op == 0) {
      uint k = rng();
      ls = ds.rank(l, r, k);
    } else {
      uint k = rng() % (r - l);
      ls = ds.kth(l, r, k);
    }
    ans ^= ls;
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"