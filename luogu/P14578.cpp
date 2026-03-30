#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M);
  flow_lm<ll> g(N, 0, 0);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  if (g.check().fi) {
    print("Yes");
    for (Z [a, b, c] : g.get_flow_es()) print(c);
  } else {
    print("No");
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"