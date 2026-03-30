#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  flow_lm<ll> g(N, s, t);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  Z [ok, f] = g.qmax();
  if (not ok) print('N');
  else print(f);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"