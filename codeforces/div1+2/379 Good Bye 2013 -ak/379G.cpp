#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"

using T = array<array<short, 3>, 3>;

constexpr T unit = []() {
  T s{};
  FOR(i, 3) FOR(k, 3) s[i][k] = -2500;
  return s;
}();

struct dat {
  int n, b;
  vc<T> dp;
};

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i), g[b].ep(a, i);
  }

  vc<char> vis(N), ok(M);
  Z f = [&](Z &f ,int n, int p) -> dat {
    vis[n] = 1;
    vc<dat> sub;
    int b = -1;
    for (Z &&e : g[n]) if (not ok[e.id] and e != p) {
      ok[e.id] = 1;
      if (vis[e]) {
        b = e;
        continue;
      }
      sub.ep(f(f, e, n));
    }
    int sz = si(sub);
    FOR(i ,sz - 1) if (sub[i].b != -1 and sub[i].b != n) swap(sub[i], sub[sz - 1]);
    dat x{1, -1, {unit, unit}};
    x.dp[0][0][0] = x.dp[1][1][0] = 0, x.dp[0][2][0] = 1;
    for (var y : sub) {
      if (y.b == n or y.b == -1) {
        vc<T> dp(x.n + y.n + 1, unit);
        FOR(a, 3) FOR(b, 3) FOR(c, y.b == -1 ? 1 : 3) if (a + b != 3 and a + c != 3) {
          FOR(i, x.n + 1) FOR(k, y.n + 1) {
            chmax(dp[i + k][a][0], x.dp[i][a][0] + y.dp[k][b][c]);
          }
        }
        x.n += y.n, x.dp = dp;
        continue;
      }
      vc<T> dp(x.n + y.n + 1, unit);
      FOR(a, 3) FOR(b, 3) FOR(c, 3) if (a + b != 3) {
        FOR(i, x.n + 1) FOR(k, y.n + 1) {
          chmax(dp[i + k][a][c], x.dp[i][a][0] + y.dp[k][b][c]);
        }
      }
      x.b = y.b, x.n += y.n, x.dp = dp;
    }
    if (b != -1) {
      FOR(i, x.n + 1) {
        int a = x.dp[i][0][0], b = x.dp[i][1][0], c = x.dp[i][2][0];
        x.dp[i] = unit, x.dp[i][0][0] = a, x.dp[i][1][1] = b, x.dp[i][2][2] = c;
      }
      x.b = b;
    }
    return x;
  };
  dat x(f(f, 0, -1));
  vc<ll> rs(N + 1);
  FOR(i, N + 1) FOR(k, 3) chmax(rs[i], x.dp[i][k][0]);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}