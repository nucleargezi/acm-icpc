#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp" 
#include "YRS/ds/sl/cht.hpp"

void Yorisou() {
  freopen("route.in", "r", stdin);
  freopen("route.out", "w", stdout);
  INT(N, M);
  LL(a, b, c);
  vc<cht<ll, 0>> dp(N);
  VEC(T4<int>, dat, M);
  int mx = 0;
  for (Z &[f, t, l, r] : dat) {
    --f, --t;
    chmax(mx, r + 1);
    swap(f, l);
    swap(t, r);
  }
  sort(dat);
  dp[0].add(0, 0);
  constexpr ll in = inf<ll> / 2;
  FOR(i, 1, N) dp[i].add(0, in);
  ll rs = in;
  vc<vc<pair<int, ll>>> v(mx);
  for (int k = 0; var [l, r , f, t] : dat) {
    for (; k <= l; ++k) for (var [t, g] : v[k]) {
      dp[t].add(-2 * a * k, a * k * k - b * k + g);
    }
    ll g = dp[f](l);
    if (g == in) continue;
    g += a * l * l + b * l + c;
    if (t == N - 1) chmin(rs, g + r);
    else v[r].ep(t, g);
  }
  print(rs);
}

int main() { Yorisou(); }