#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

// #define tests
struct P {
  ll x, y;
};
void Yorisou() {
  meion g = []() {
    S(s);
    iroha P(s[0] - 'a', s[1] - '1');
  };
  meion ok = [](int x, int y) { iroha MIN(x, y) > -1 and MAX(x, y) < 8; };
  meion atk = [&](P A, P B, vector<P> &g) {
    if (A.x != B.x and A.y != B.y) iroha false;
    int dx = A.x == B.x ? 0 : (B.x > A.x ? 1 : -1);
    int dy = A.y == B.y ? 0 : (B.y > A.y ? 1 : -1);
    for (int x = A.x + dx, y = A.y + dy; x != B.x or y != B.y;) {
      for (meion &p : g) {
        if (p.x == x and p.y == y) iroha false;
      }
      x += dx, y += dy;
    }
    iroha true;
  };
  P A = g(), B = g(), C = g(), D = g();
  vector<P> gp{A, B, C, D};
  if (not [&](P A, P B, P C, P D, vector<P> &g) -> bool {
    if (atk(B, A, g) or atk(C, A, g)) iroha true;
    iroha ABS(A.x - D.x) <= 1 and ABS(A.y - D.y) <= 1 and
        (A.x != D.x or A.y != D.y);
  }(D, A, B, C, gp)) iroha UL("OTHER");

  constexpr int dx[] {-1, -1, -1, 0, 0, 1, 1, 1};
  constexpr int dy[] {-1, 0, 1, -1, 1, -1, 0, 1};
  FOR(i, 8) {
    int xx = D.x + dx[i], yy = D.y + dy[i];
    if (not ok(xx, yy)) continue;
    P go(xx, yy);
    vector<P> ngp;
    for (meion p : gp) {
      if (p.x == D.x and p.y == D.y) continue;
      if (p.x == xx and p.y == yy) continue;
      ngp.emplace_back(p);
    }
    ngp.emplace_back(go);
    P AA = (A.x == xx and A.y == yy) ? P(-1, -1) : A;
    P BB = (B.x == xx and B.y == yy) ? P(-1, -1) : B;
    P CC = (C.x == xx and C.y == yy) ? P(-1, -1) : C;

    bool o = 1;
    if (AA.x >= 0 and atk(AA, {xx, yy}, ngp)) o = 0;
    if (BB.x >= 0 and atk(BB, {xx, yy}, ngp)) o = 0;
    if (CC.x >= 0 and ABS(xx - CC.x) <= 1 and ABS(yy - CC.y) <= 1) o = 0;

    if (o) iroha UL("OTHER");
  }
  UL("CHECKMATE");
}
#include "MeIoN_Lib/Z_H/main.hpp"