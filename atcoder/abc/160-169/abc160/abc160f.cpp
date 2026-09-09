#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/re_dp.hpp"
#include "YRS/mod/binom.hpp"

using T = M11;
binom<T> C;

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  using X = pair<int, T>;
  Z fee = [&](const X &a, const X &b) -> X {
    return {a.fi + b.fi, a.se * b.se};
  };
  Z fev = [&](const X &a, int i) -> X {
    return {a.fi + 1, a.se * C.inv(a.fi + 1)};
  };
  Z fve = [&](const X &a, Z) -> X { return a; };
  re_dp<int, X> dp(g, fee, fev, fve, {0, 1});
  FOR(i, N) print(dp[i].se * C.fac(N));
}

int main() { Yorisou(); }