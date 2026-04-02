#include "YRS/all.hpp"
#include "YRS/flow/max_flow.hpp"

void before() {}

// #define tests
void yorisou() {
  INT(n, m, h, d);
  Z I = [&](int a, int b, int c) -> int {
    return a * (m * (h + 1)) + b * (h + 1) + c;
  };
  Z O = [&](int a, int b, int c) -> int {
    return min({a, b, c}) > -1 and a < n and b < m and c < h + 1;
  };

  const int s {n * m * (h + 1)}, t {s + 1}, N(t + 1);
  constexpr int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  max_flow<ll> FL(N, s, t);
  FOR(j, h) FOR(i, n) FOR(k, m) {
    INT(x);
    FL.add(I(i, k, j), I(i, k, j + 1), x);
    FOR(l, 4) {
      int xx {i + dx[l]}, yy {k + dy[l]};
      if (O(xx, yy, j + d)) {
        FL.add(I(xx, yy, j + d), I(i, k, j), inf<int>);
      }
    }
  }
  FOR(i, n) FOR(k, m) FL.add(s, I(i, k, 0), inf<int>);
  FOR(i, n) FOR(k, m) FL.add(I(i, k, h), t, inf<int>);
  print(FL.flow());
}