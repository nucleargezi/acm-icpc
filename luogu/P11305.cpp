#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/string/runs.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/al/m/max.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  for (char &c : s) c -= 'a';
  
  sam ss(si(s));
  vc<int> V = ss.slv(s).se, en = std::move(ss.en);
  int M = si(ss);
  vc<PII> dp(M, {M, -1});
  FOR(i, N) dp[en[i]] = {i, i};
  reverse(V);
  pop(V);
  int rs = 0;
  for (int n : V) {
    var [l, r] = dp[n];
    int sz = ss[n].sz;
    if (l + sz <= r) chmax(rs, sz);
    int p = ss[n].fa;
    chmin(dp[p].fi, l);
    chmax(dp[p].se, r);
  }

  seg_dual_t<Max<int>> L(N), R(L);
  for (Z [l, r ,p] : runs(s)) {
    int sz = r - l;
    for (int k = 1; 2 * k * p <= sz; ++k) {
      int sq = 2 * k * p;
      L.apply(l + sq - 1, r, sq);
      R.apply(l, r - sq + 1, sq);
    }
  }
  FOR(i, 1, N) chmax(rs, (L[i - 1] + R[i]) / 2);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}