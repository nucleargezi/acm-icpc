#include "YRS/all.hpp"

void Yorisou() {
  INT(N, M);
  STR(s);
  int sz = si(s);
  FOR(i, sz) s[i] -= '0';
  vc<vc<int>> r;
  Z f = [&](int x) {
    vc<int> a;
    int st{};
    FOR(i, sz) {
      st = st * 10 + s[i];
      if (st > 81) return;
      if (st % x == 0) {
        if (st / x >= 10) return;
        a.ep(st / x);
        st = 0;
        if (si(a) == M) r.ep(a);
      }
    }
  };
  FOR(i, 1, 10) f(i);
  using T = pair<vc<int>, vc<int>>;
  T rs{{}, {}};
  Z ls = [](const T &a, const T &b) -> bool {
    if (a.fi.empty()) return 1;
    if (a.fi != b.fi) return a.fi > b.fi;
    return a.se > b.se;
  };
  Z g = [&](const vc<int> &b) {
    int p = 0;
    vc<int> ret;
    FOR(i, N) {
      bool ok = 0;
      FOR(k, not i, 10) if (not ok) {
        string seg;
        for (int x : b) {
          x *= k;
          if (x >= 10) seg += char(x / 10), seg += char(x % 10);
          else seg += char(x);
        }
        int le = si(seg);
        if (p + le <= sz and seg == s.substr(p, le)) {
          ret.ep(k);
          ok = 1;
          p += le;
        }
      }
      if (not ok) return;
    }
    if (p == sz and ls(rs, {ret, b})) rs = {ret, b}; 
  };
  for (const Z &s : r) g(s);
  if (rs.fi.empty()) Impossible();
  else {
    string s;
    for (int x : rs.fi) s += char(x + '0');
    put(s);
    put(' ');
    s.clear();
    for (int x : rs.se) s += char(x + '0');
    print(s);
  }
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"