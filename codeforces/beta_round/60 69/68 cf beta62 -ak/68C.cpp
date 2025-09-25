#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"

// #define tests
using T = tuple<int, int, int, int, int>;
using A = retsu<int>;
void Yorisou() {
  INT(N);
  const int M = N * (N - 1) / 2;
  VEC(T, e, M);
  A L(N, N), R(N, N), a(N, N);
  for (Z &[f, t, l, r, c] : e) {
    --f, --t;
    ++r;
    L[f][t] = l;
    R[f][t] = r;
    a[f][t] = c;
  }
  A FL(N, N);
  PII ans = {inf<int>, 0};
  Z f = [&](Z &f, int n, int cost) -> void {
    if (n == N * N) {
      int flow = 0;
      FOR(i, 1, N) flow += FL[0][i];
      chmin(ans.FI, flow);
      if (ans.FI == flow) chmax(ans.SE, cost);
      return;
    }
    Z [x, y] = divmod(n, N);
    if (x >= y) return f(f, n + 1, cost);
    if (y == N - 1) {
      int flow = 0;
      FOR(i, x) flow += FL[i][x];
      FOR(i, x + 1, N - 1) flow -= FL[x][i];
      if (x == 0) flow = L[x][y];
      if (flow < L[x][y] or flow >= R[x][y]) return;
      FL[x][y] = flow;
      cost += flow == 0 ? 0 : a[x][y] + flow * flow;
      f(f, n + 1, cost);
      return;
    }
    FOR(flow, L[x][y], R[x][y]) {
      int cc = flow == 0 ? 0 : a[x][y] + flow * flow;
      FL[x][y] = flow;
      f(f, n + 1, cost + cc);
    }
  };
  f(f, 0, 0);
  if (ans.FI == inf<int>) ans = {-1, -1};
  print(ans);
}
#include "YRS/Z_H/main.hpp"