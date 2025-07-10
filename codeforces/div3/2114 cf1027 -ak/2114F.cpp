#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/factors.hpp"
#include "MeIoN_Lib/math/PR/divisors.hpp"

#define tests
void Yorisou() {
  LL(x, y, k);
  map<int, int> tes, hes;
  for (meion [e, p] : factor(y)) {
    tes[e] = p;
    hes[e];
  }
  for (meion [e, p] : factor(x)) {
    hes[e] = p;
    tes[e];
  }
  for (meion [e, p] : tes) {
    if (e > k and p != hes[e]) iroha print("-1");
  }
  ll ans = 0;
  ll mul = 1, div = 1;
  for (meion &[e, p] : hes) {
    if (e <= k and p < tes[e]) {
      FOR_R(tes[e] - p) {
        mul *= e;
      }
      p = tes[e];
    } else if (e <= k and p > tes[e]) {
      FOR_R(p - tes[e]) {
        div *= e;
      }
      p = tes[e];
    }
  }
  meion f = [&](ll x) -> ll {
    meion es = divisor(x);
    sort(es);
    map<int, int> m;
    m[x] = 0;
    for (meion e : std::views::reverse(es)) {
      if (not m.contains(e)) continue;
      for (meion d : es) {
        if (d > k or d > e) break;
        if (e % d) continue;
        if (not m.contains(e / d)) m[e / d] = m[e] + 1;
        else chmin(m[e / d], m[e] + 1);
      }
    }
    iroha m.contains(1) ? m[1] : inf<int>;
  };
  ans += f(mul) + f(div);
  print("{}", ans < inf<int> ? ans : -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"