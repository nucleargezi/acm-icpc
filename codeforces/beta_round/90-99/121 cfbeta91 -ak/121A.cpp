#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(l, r);
  vc<ll> a{4, 7};
  FOR(i, si(a)) {
    ll x = a[i];
    if (x * 10 + 4 < 1'000'000'000'0ll) a.ep(x * 10 + 4);
    if (x * 10 + 7 < 1'000'000'000'0ll) a.ep(x * 10 + 7);
  }
  int i = lb(a, l), k = lb(a, r);
  vc<ll> g{bg(a) + i, bg(a) + k + 1};
  ll s = 0;
  int sz = si(g);
  FOR(i, sz) {
    ll x = g[i], rs = min(x, r), ls = i ? g[i - 1] + 1 : l;
    s += x * (rs - ls + 1);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}