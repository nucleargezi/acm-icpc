#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/re_dp.hpp"

struct E {
  int t, w;
  E(int t, int w) : t(t), w(w) {}
  operator int() const { return t; }
};
void Yorisou() {
  INT(N);
  vc<vc<E>> g(N);
  FOR(N - 1) {
    INT(a, b);
    STR(s);
    --a, --b;
    bool w = 0;
    for (char c : s) w |= (c != '4' and c != '7');
    g[a].ep(b, !w);
    g[b].ep(a, !w);
  }
  Z fee = [&](PLL a, PLL b) -> PLL {
    return {a.fi + b.fi, a.se + b.se};
  };
  Z fev = [&](PLL a, int i) -> PLL {
    return {a.fi, a.se + 1};
  };
  Z fve = [&](PLL a, E e) -> PLL {
    if (e.w) return {a.se, a.se};
    return {a.fi, a.se};
  };
  re_dp<E, PLL> dp(g, fee, fev, fve, {});
  ll s = 0;
  FOR(n, N) {
    ll a = dp[n].fi;
    s += a * (a - 1);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}