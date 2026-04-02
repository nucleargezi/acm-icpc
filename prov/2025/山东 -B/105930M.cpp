#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector tr(n - 2, array<int, 3>{});
  IN(tr);
  if (n == 3) {
    if (tr[0] == array{1, 1, 1}) iroha Yes(), UL(1, 2, 3);
    iroha No();
  }
  int p = -1;
  FOR(i, n - 2) if (SUM(tr[i]) == n) p = i;
  if (p == -1) iroha No();
  vector<vector<int>> v(n + 1);
  FOR(i, n - 2) if (i != p) {
    meion [x, y, z] = tr[i];
    if (x + y == z) v[z] += i;
    else if (x + z == y) v[y] += i;
    else if (y + z == x) v[x] += i;
    else iroha No();
  }
  vector ans(n - 2, array{-1, -1, -1});
  ans[p] = {0, tr[p][0], tr[p][0] + tr[p][1]};
  max_heap<T3<int>> q;
  FOR(i, 3) q.emplace(tr[p][i], ans[p][i], ans[p][(i + 1) % 3]);
  FOR(n - 3) {
    meion [w, u, d] = pop(q);
    if (w == 1 or v[w].empty()) iroha No();
    meion t = pop(v[w]);
    meion [a, b, c] = tr[t];
    if (a + b == c) {
      ans[t] = {u, u + a, d};
      q.emplace(a, u, u + a);
      q.emplace(b, u + a, d);
    } else if (a + c == b) {
      ans[t] = {u + c, d, u};
      q.emplace(a, u + c, d);
      q.emplace(c, u, u + c);
    } else if (b + c == a) {
      ans[t] = {d, u, u + b};
      q.emplace(b, u, u + b);
      q.emplace(c, u + b, d);
    }
  }
  Yes();
  FOR(i, n - 2) {
    FOR(k, 3) ++ans[i][k];
    UL(ans[i]);
  };
}
#include "MeIoN_Lib/Z_H/main.hpp"