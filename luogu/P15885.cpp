#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = ll;
struct P {
  using cp = const P &;
  T x = 0, y = 0;
  P &operator+=(cp p) { return x += p.x, y += p.y, *this; }
  P &operator-=(cp p) { return x -= p.x, y -= p.y, *this; }
  P operator+(cp p) const { return P(*this) += p; }
  P operator-(cp p) const { return P(*this) -= p; }
  T dot(cp p) const { return x * p.x + y * p.y; }
  T det(cp p) const { return x * p.y - y * p.x; }
};
using cp = P::cp;

int ccw(cp a, cp b, cp c) {
  T x = (b - a).det(c - a);
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int check(cp f, cp t, pair<P, P> re) {
  var [a, b] = re.fi;
  var [c, d] = re.se;
  int st;
  int o = ccw(f, t, P{a, b});
  int p = ccw(f, t, P{c, d});
  if (o and p and o != p) return 0;
  if (o) st = o;
  else if (p) st = p;
  o = ccw(f, t, P{a, d});
  p = ccw(f, t, P{c, b});
  if (o and p and o != p) return 0;
  if (o) st = o;
  else if (p) st = p;
  return st;
}

void slv() {
  INT(N);
  vc<pair<P, P>> dat(N);
  FOR(i, N) {
    INT(x, y);
    dat[i].fi = {x, y};
    IN(x, y);
    dat[i].se = {x, y};
  }
  vc<int> I(N);
  FOR(i, N) I[i] = i;
  vc<P> buf(N * N);
  Z f = [&](Z &f, const vc<int> &I) -> bool {
    if (si(I) <= 2) return 1;
    buf.clear();
    for (int i : I){
      buf.ep(dat[i].fi), buf.ep(dat[i].se);
      buf.ep(dat[i].fi.x, dat[i].se.y);
      buf.ep(dat[i].se.x, dat[i].fi.y);
    }
    int n = si(buf);
    vc<int> ls, rs;
    FOR(i, n) FOR(k, i + 1, n) {
      P fir = buf[i], to = buf[k];
      bool ok = 1;
      for (int id : I) {
        ok &= not not check(fir, to, dat[id]);
        if (not ok) break;
      }
      if (not ok) continue;
      ls.clear(), rs.clear();
      for (int id : I) {
        if (check(fir, to, dat[id]) == -1) ls.ep(id);
        else rs.ep(id);
      }
      if (ls.empty() or rs.empty()) continue;
      return f(f, ls) and f(f, rs);
    }
    return 0;
  };
  if (f(f, I)) print(N - 1);
  else print("impossible");
}

int main() { slv(); }