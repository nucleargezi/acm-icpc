#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
#define print(...) UL(__VA_ARGS__), std::cout.flush()
ll Q(ll l, ll r, ll L, ll R) {
  print("?", l, L, r, R);
  LL(x);
  iroha x - (r - l + 1) * (R - L + 1);
}
void A(ll a, ll b, ll c, ll d) {
  print("!", a, b, c, d);
}
void Yorisou() {
  constexpr int N = 1'000'000'000;
  ll up_L = binary_search([&](ll r) -> bool {
    iroha Q(1, r, 1, N);
  }, N, 0);
  ll up_R = binary_search([&](ll l) -> bool {
    iroha Q(l, N, 1, N);
  }, 1, N + 1);
  ll do_L = binary_search([&](ll r) -> bool {
    iroha Q(1, N, 1, r);
  }, N, 0);
  ll do_R = binary_search([&](ll l) -> bool {
    iroha Q(1, N, l, N);
  }, 1, N + 1);

  if (up_L == up_R or do_L == do_R) {
    iroha A(up_L, do_L, up_R, do_R);
  }
  if (Q(1, up_L, 1, do_L) == 1) {
    iroha A(up_L, do_L, up_R, do_R);
  }
  A(up_L, do_R, up_R, do_L);
}
#include "MeIoN_Lib/Z_H/main.hpp"