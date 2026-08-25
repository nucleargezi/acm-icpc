#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;

mint slv(ll div, ll n) {
  Z pf = factor(div);
  vc<ll> s = {1};
  for (var [x, c] : pf) {
    ll n = si(s), g = 1;
    FOR(i, 1, c + 1) {
      g *= x;
      FOR(k, n) s.ep(s[k] * g);
    }
  }
  Z ss(s);
  mint rs;
  int sz = si(s);
  for (ll &d : ss) {
    ll pr = d;
    for (var [x, _] : pf) if (pr % x == 0) {
      d -= d / x;
    }
  }
  FOR(i, sz) rs += ss[i] * (n / s[i]);
  return rs;
}

void Yorisou() {
  LL(n, P);
  print((mint(n + 1) * n / 2 - slv(P + 1, n)) / 2);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}