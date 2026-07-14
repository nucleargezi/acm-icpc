#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  int ms = (1 << M) - 1;
  vc<int> mp(N + 2);
  FOR(i, N) FOR(k, M) {
    INT(x);
    if (x) mp[i] |= 1 << k;
  }

  struct dat {
    int vis, nx, s;
  };
  vc<dat> st;
  Z f = [&](Z &f, int c, int vis, int nx, int s) -> void {
    if (c >= M) return st.ep(vis, nx, s), void();
    f(f, c + 1, vis, nx, s);
    if (c + 2 <= M) {
      int msk = 3 << c;
      if (not(vis & msk)) f(f, c + 2, vis | msk, nx | msk, s + 1);
    }
    if (c + 3 <= M) {
      int msk = 7 << c;
      if (not(vis & msk)) f(f, c + 3, vis | msk, nx, s + 1);
    }
  };
  f(f, 0, 0, 0, 0);
  int sz = 1 << (M + M), in = -inf<int>;
  vc<int> dp(sz, in), ndp(dp), v{0}, vv;
  dp[0] = 0;
  FOR(i, N) {
    vv.clear();
    for (int x : v) if (dp[x] >= 0) {
      int c = x & ms, nx = x >> M, s = dp[x];
      for (dat g : st) {
        if ((g.vis & (c | mp[i])) or (g.vis & (nx | mp[i + 1])) or
            (g.nx & mp[i + 2]))
          continue;
        int ns = nx | g.vis | (g.nx << M), ss = s + g.s;
        if (ndp[ns] == in) vv.ep(ns);
        chmax(ndp[ns], ss);
      }
    }
    for (int x : v) dp[x] = in;
    dp.swap(ndp);
    v.swap(vv);
  }
  print(dp[0]);
}

int main() {
  Yorisou();
  return 0;
}