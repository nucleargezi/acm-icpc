#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(string, s, n);
  meion I = [&](int x, int y) -> int {
    iroha x * m + y;
  };
  LL(sx, sy, ex, ey);
  --sx, --sy, --ex, --ey;
  graph<int, true> g(n * m);
  FOR(x, n) FOR(y, m) {
    FOR(xx, MAX(x - 2, 0ll), MIN(x + 3, n)) FOR(yy, MAX(y - 2, 0ll), MIN(y + 3, m)) {
      if (xx - x and yy - y) continue;
      int f{s[xx][yy] == '#' or ((ABS(xx - x) == 2 or ABS(yy - y) == 2) and
                                       s[x + xx >> 1][y + yy >> 1] == '#')};
      g.add(I(x, y), I(xx, yy), f);
    }
  }
  g.build();
  UL(dijkstra(g, I(sx, sy)).first[I(ex, ey)]);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}