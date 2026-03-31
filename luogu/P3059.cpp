#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  string s[10];
  INT(K, N);
  FOR(i, K) IN(s[i]);
  retsu<int> pr(N + 1, K);
  FOR(k, K) FOR(i, N) {
    pr[i + 1][k] = s[k][i] == '(' ? 1 : -1;
    pr[i + 1][k] += pr[i][k];
  }
  vc<int> R(N + 1, N + 1);
  FOR(k, K) {
    vc<int> st;
    FOR_R(i, N + 1) {
      while (si(st) and pr[st.back()][k] >= pr[i][k]) pop(st);
      if (si(st)) chmin(R[i], st.back());
      st.ep(i);
    }
  }
  vc<int> I(N + 1);
  iota(all(I), 0);
  sort(I, [&](int i, int k) -> bool {
    FOR(j, K) if (pr[i][j] != pr[k][j]) return pr[i][j] < pr[k][j];
    return i < k;
  });
  Z f = [&](int i, int k) -> bool {
    FOR(j, K) if (pr[i][j] != pr[k][j]) return 0;
    return 1;
  };
  ll ans = 0;
  for (int l = 0, r; l < N + 1; l = r) {
    r = l + 1;
    while (r <= N and f(I[l], I[r])) ++r;
    FOR(i, l, r) ans += lb(bg(I) + i + 1, bg(I) + r, R[I[i]]);
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"