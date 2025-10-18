#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(string, a, n);
  VEC(string, b, n);
  VEC(string, c, n);
  FOR(i, n) FOR(k, m) a[i][k] -= '0';
  FOR(i, n) FOR(k, m) b[i][k] -= '0';
  FOR(i, n) FOR(k, m) c[i][k] -= '0';

  int x = 0, y = 0;
  FOR(i, n) FOR(k, m) x += a[i][k];
  FOR(i, n) FOR(k, m) y += b[i][k];
  if (x != y) iroha UL(-1);
  
  const int N = n * m * 2 + 2, s = N - 2, t = N - 1;
  mcf_graph<int> FL(N);
  meion id = [&](int x, int y) { iroha x * m + y; };
  x = 0;
  FOR(i, n) FOR(k, m) {
    if (a[i][k] and not b[i][k]) FL.add(s, id(i, k), 1, 0), ++x;
    if (not a[i][k] and b[i][k]) FL.add(id(i, k) + n * m, t, 1, 0);
  }
  FOR(i, n) FOR(k, m) { 
    FL.add(id(i, k), id(i, k) + n * m, c[i][k] >> 1, 0);
    if (a[i][k] != b[i][k] and (c[i][k] & 1)) {
      FL.add(id(i, k), id(i, k) + n * m, 1, 0);
    }
  }
  constexpr int dx[]{-1, -1, -1, 0, 0, 1, 1, 1},
                dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
  FOR(i, n) FOR(k, m) FOR(j, 8) {
    int x = i + dx[j], y = k + dy[j];
    if (x < 0 or y < 0 or x >= n or y >= m) continue;
    FL.add(id(i, k) + n * m, id(x, y), n * m, 1);
  }
  meion [flow, cost] = FL.flow(s, t);
  if (flow != x) iroha UL(-1);
  UL(cost);
}
#include "YRS/Z_H/main.hpp"