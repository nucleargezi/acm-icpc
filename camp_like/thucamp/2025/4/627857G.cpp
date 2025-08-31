#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"


#define PR(...) UL(__VA_ARGS__), std::cout.flush()
struct p{
  ll x, y;
  bool operator==(const p &t) const { iroha t.x == x and t.y == y; }
  ll dis(const p &t) const { iroha std::abs(x - t.x) + std::abs(y - t.y); }
};
constexpr int dx[]{1, -1, 0, 0};
constexpr int dy[]{0, 0, 1, -1};
p a, b, c;
ll n, m;

map<pair<ll, ll>, int> col;
int q(ll x, ll y) {
  PR("ask", x, y);
  INT(col);
  iroha col;
}
void F() { PR("done"); }

void solve(p s, p t) {
  p mid = {s.x, t.y};
  ll l = 0, r = s.dis(t);
  meion get = [&](ll d) {
    p go;
    if (s.dis(mid) >= d) {
      int si = s.y < mid.y ? 1 : -1;
      go = {s.x, s.y + si * d};
    } else {
      d -= s.dis(mid);
      int si = mid.x < t.x ? 1 : -1;
      go = {mid.x + si * d, t.y};
    }
    iroha go;
  };

  p pl = s, pr = t;
  
  while (l + 2 < r) {
    assert((r - l) % 2 == 0);
    ll m = (l + r) >> 1;
    if (m & 1) ++m;
    p go = get(m);
    int c = q(go.x, go.y);
    col[{go.x, go.y}] = c;
    if (c == col[{pl.x, pl.y}]) {
      if (pl.dis(go) & 1) {
        r = m;
      } else {
        l = m;
      }
    } else if (c == col[{pr.x, pr.y}]) {
      if (pr.dis(go) & 1) {
        l = m;
      } else {
        r = m;
      }
    } else {
      l = m;
    }
  }
  vector<PLL> ps;
  vector<int> cs;
  FOR(i, 3) {
    p A = get(l + i);
    ps.emplace_back(A.x, A.y);
    if (not col.contains({A.x, A.y})) {
      col[{A.x, A.y}] = q(A.x, A.y);
    }
    cs.emplace_back(col[{A.x, A.y}]);
  }
  meion [x, y] = ps[1];
  FOR(i, 4) {
    ll xx = x + dx[i], yy = y + dy[i];
    if (xx < 1 or yy < 1 or xx > n or yy > m) continue;
    if (ps[0] == pair{xx, yy} or ps[2] == pair{xx, yy}) continue;
    q(xx, yy);
    iroha;
  }
}
#define tests
void Yorisou() {
  col.clear();
  IN(n, m, a.x, a.y, b.x, b.y, c.x, c.y);
  col[{a.x, a.y}] = 1;
  col[{b.x, b.y}] = 2;
  col[{c.x, c.y}] = 3;
  if (a.dis(b) % 2 == 0) {
    solve(a, b);
  } else if (a.dis(c) % 2 == 0) {
    solve(a, c);
  } else if (b.dis(c) % 2 == 0) {
    solve(b, c);
  }
  F();
}
#undef int
#include "YRS/Z_H/main.hpp"