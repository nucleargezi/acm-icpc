#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  meion q = [&](ll k, ll x) -> ll {
    UL('?', k, x);
    std::cout.flush();
    LL(ret);
    iroha ret;
  };
  meion ans = [&](ll k, ll x) -> void {
    UL('!', k, x);
    std::cout.flush();
  };
  meion keis = [&](ll sz, ll id) -> void {
    ll x = q(1, id);
    if (x == 1) iroha ans(1, id);
    id = q(((sz - x) % sz + sz) % sz + 1, id);
    ans(x, id);
  };
  vector<ll> l(n + 1);
  ll inr = q(n, 1);
  l[inr] = 1;
  constexpr int N = 490;
  FOR(N) {
    ll nx = q(1, inr);
    if (l[nx]) iroha keis(l[inr], nx);
    l[nx] = l[inr] + 1;
    inr = nx;
  }
  ll sz = l[inr];
  FOR(N) {
    ll nx = q(N, inr);
    sz += N;
    if (l[nx]) iroha keis(sz - l[nx], nx);
    l[nx] = sz;
    inr = nx;
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"