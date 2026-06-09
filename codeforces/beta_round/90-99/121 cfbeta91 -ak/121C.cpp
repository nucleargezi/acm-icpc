#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  vc<ll> a{4, 7};
  FOR(i, si(a)) {
    ll x = a[i];
    if (x * 10 + 4 <= N) a.ep(x * 10 + 4);
    if (x * 10 + 7 <= N) a.ep(x * 10 + 7);
  }

  vc<ll> fac{1};
  FOR(i, 1, 20) fac.ep(fac.back() * i);

  if (N < 13 and K > fac[N]) return print(-1);

  int n = min(N, 13);
  vc<int> v = [&]() {
    vc<int> rs;
    --K;
    bool vis[20]{};
    FOR(i, n) FOR(k, n) if (not vis[k]) {
      if (K < fac[n - i - 1]) {
        rs.ep(k);
        vis[k] = 1;
        break;
      } else K -= fac[n - i - 1];
    }
    return rs;
  }();
  int rs = 0;
  FOR(i, n) if (fd(a, N - n + 1 + i) and fd(a, N - n + 1 + v[i])) ++rs;
  for (int x : a) if (x < N - n + 1) ++rs;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}