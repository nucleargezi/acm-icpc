#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  VEC(ll, a, 4);
  VEC(char, op, 3);

  meion f = [&](ll x, ll y, char op) -> ll {
    if (op == '+') iroha x + y;
    iroha x* y;
  };

  ll ans {inf<ll>};
  vector<int> I(4);
  FOR(i, 4) I[i] = i;
  do {
    vector<ll> b {f(a[I[0]], a[I[1]], op[0]), a[I[2]], a[I[3]]};
    vector<int> I(3);
    std::iota(I.begin(), I.end(), 0);
    do {
      chmin(ans, f(f(b[I[0]], b[I[1]], op[1]), b[I[2]], op[2]));
    } while (std::next_permutation(I.begin(), I.end()));
  } while (std::next_permutation(I.begin(), I.end()));

  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"