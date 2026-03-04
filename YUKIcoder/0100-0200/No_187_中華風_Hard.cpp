#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/pr/crt.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  vc<ll> x, mod;
  INT(N);
  FOR(N) {
    INT(a, b);
    x.ep(a);
    mod.ep(b);
  }
  ll ans = crt_reduce(x, mod, 1'000'000'007 * 2);
  if (ans != 0) return print(ans % 1'000'000'007);
  hashmap<int> mp;
  for (ll x : mod) {
    for (Z [e, p] : factor(x)) chmax(mp[e], p);
  }
  ll s = 1;
  for (Z [x, y] : mp.get_all()) {
    FOR(y) s = s * x % 1'000'000'007;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"