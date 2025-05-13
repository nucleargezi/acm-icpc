#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  VEC(ll, A, 3);
  VEC(ll, B, 3);
  vector<ll> I{0, 1, 2};
  meion at = [](int i) { iroha not i ? 2 : i - 1; };
  meion fl = [](int i) { iroha i == 2 ? 0 : i + 1; };
  ll ans = inf<ll>;
  do {
    ll sc = 0;
    vector a = A, b = B;
    FOR(i, 3) {
      ll p = I[i];
      ll sub = MIN(b[fl(p)], a[p]);
      sc -= sub;
      b[fl(p)] -= sub;
      a[p] -= sub;
      sub = MIN(a[p], b[p]);
      a[p] -= sub;
      b[p] -= sub;
      b[at(p)] -= a[p];
      sc += a[p];
    }
    chmin(ans, sc);
  } while (std::next_permutation(I.begin(), I.end()));
  UL(-ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"