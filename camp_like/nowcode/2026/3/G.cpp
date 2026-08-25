#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

vc<PII> up(const vc<PII> &a) {
  static vc<PII> rs;
  rs.clear();
  for (var [x, y] : a) {
    if (si(rs) and rs.back().se == y) continue;
    if (rs.empty()) {
      rs.ep(x, y);
    } else {
      Z [xx, yy] = rs.back();
      if (x < xx) rs.ep(x, y);
    }
  }
  return rs;
}

vc<PII> lo(const vc<PII> &a) {
  static vc<PII> rs;
  rs.clear();
  for (var [x, y] : a) {
    while (si(rs) and rs.back().fi <= x) pop(rs);
    rs.ep(x, y);
  }
  return rs;
}

bool cmp(const PII &a, const PII &b) {
  return a.se < b.se or (a.se == b.se and a.fi < b.fi);
}

void Yorisou() {
  INT(N, M);
  RET(int, a, N, M);
  for (int &x : a.a) --x;
  vc<vc<PII>> v(N * M);
  FOR(i, N) FOR(k, M) v[a[i][k]].ep(i, k);
  retsu<int> c(N + 2, M + 2);
  Z ad = [&](int x, int y, int xx, int yy) {
    if (x < xx and y < yy) {
      ++x, ++y, ++xx, ++yy;
      ++c[x][y];
      ++c[xx + 1][yy + 1];
      --c[x][yy + 1];
      --c[xx + 1][y];
    }
  };
  for (Z &q : v) {
    sort(q, cmp);
    Z a(up(q)), b(lo(q));
    vc<PII> aa;
    for (var [x, y] : b) {
      int i = int(upper_bound(all(a), PII{x, y}, cmp) - bg(a)) - 1;
      if (i >= 0) {
        var [xx, yy] = a[i];
        aa.ep(xx, y);
      }
    }
    a.insert(ed(a), all(aa));
    unique(a);
    sort(b, cmp);
    for (var [x, y] : a) {
      int i = lower_bound(all(b), PII{x, y}, cmp) - bg(b);
      if (i != si(b)) {
        var [c, d] = b[i];
        ad(x, y, c, d);
      }
      if (i + 1 < si(b)) {
        var [c, d] = b[i + 1];
        ad(x, y, c, d);
      }
    }
  }
  c.pres();
  string s;
  FOR(i, 1, N + 1) {
    s.clear();
    FOR(k, 1, M + 1) s += '0' + (not not c[i][k]);
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}