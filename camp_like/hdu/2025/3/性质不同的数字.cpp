#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/random/rng.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector<pair<ll, ull>> go;
  FOR(n) {
    LL(l, r);
    --l;
    ull v = rng_64();
    go.emplace_back(l, v);
    go.emplace_back(r, v);
  }
  sort(go);
  set<ull> se;
  ull v = 0;
  for (ll pr = -1; meion &[l, x] : go) {
    if (l != pr) se.emplace(v);
    pr = l;
    v ^= x;
  }
  se.emplace(v);
  UL(len(se));
}
#include "MeIoN_Lib/Z_H/main.hpp"