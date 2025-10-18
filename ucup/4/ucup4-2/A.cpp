#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/IO/fast_io.hpp"

#define tests
using mint = M99;
struct edge {
  int f, to, id;
};
void Yorisou() {
  INT(N, K);
  vector<PII> e;
  FOR(i, 1, N) {
    INT(fa);
    --fa;
    e.ep(fa, i);
  }
  if (K == 1) return print(N);
  int sz = (int)std::ceil(sqrtl(N));
  int L = sz * 2;
  vector<edge> E;
  vector<int> in(N);
  for (int id = 0; Z [x, y] : e) {
    E.push_back({x, y, id + 1});
    E.push_back({y, x, id});
    ++in[x], ++in[y];
    id += 2;
  }
  const int LE = (int)E.size();
  vector<int> pr(LE, 1), g(LE, 0), ins(N, 0), dp(N, 0);
  mint ans;
  FOR(i, N) if (in[i] >= K - 1) ans += C<mint>(in[i], K - 1);
  FOR(t, L - 1) {
    fill(all(ins), 0);
    fill(all(dp), 0);
    FOR(id, LE) ins[E[id].to] += pr[id];
    FOR(id, LE) {
      int x = E[id].f, rid = E[id].id;
      int val = ins[x] - pr[rid];
      g[id] = val;
      dp[E[id].to] += val;
    }
    FOR(i, N) if (dp[i] >= K - 1) ans += C<mint>(dp[i], K - 1);
    pr.swap(g);
    fill(all(g), 0);
  }
  print(ans.val);
}
#include "YRS/Z_H/main.hpp"