#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  LL(N, M, K);
  VEC(T3<ll>, a, M);
  for (Z &[l, r, w] : a) ++r, swap(l, r), swap(l, w);
  Z I = argsort(a);
  retsu<map<ll, ll>> dp(M, N);
  retsu<map<ll, PLL>> fa(M, N);
  for (int i : I) {
    var [w, l, r] = a[i];
    FOR(t, M) {
      int id = I[t];
      if (get<0>(a[id]) >= w) break;
      FOR(c, 1, N) {
        Z &f = dp[i][c];
        Z &fp = dp[id][c - 1];
        for (ll v = l; v < r; ++v) {
          if (v % K == 0 and fp.contains(v / K) and chmax(f[v], fp[v / K] + v))
            fa[i][c][v] = {1, id};
          if (fp.contains(v - K) and chmax(f[v], fp[v - K] + v))
            fa[i][c][v] = {0, id};
        }
      }
    }
    for (ll v = l; v < r; ++v) {
      if (not dp[i][0].contains(v)) dp[i][0][v] = v, fa[i][0][v] = {-1, 0};
    }
  }

  ll mx = -1, id = -1, w = -1;
  FOR(i, M) {
    for (var [v, s] : dp[i][N - 1]) {
      if (chmax(mx, s)) id = i, w = v;
    }
  }
  if (mx == -1) return NO();
  
  vc<PLL> rs;
  for (int i = N; i--; ) {
    var [op, fi] = fa[id][i][w];
    rs.ep(id + 1, w);
    id = fi;
    if (op == 1) w /= K;
    else w -= K;
  }
  reverse(rs);
  YES();
  for (var [a, b] : rs) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}