#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  STR(s);
  FOR(i, N) s[i] -= '0';
  int c[10]{};
  vc<int> v[10];
  FOR(i, N) ++c[(int)s[i]], v[(int)s[i]].ep(i);

  Z get = [&](int t) -> pair<int, string> {
    int nd = max(0, K - c[t]), rs = 0;
    FOR(d, 1, 10) {
      if (t - d >= 0) {
        int g = min(nd, c[t - d]);
        rs += g * d;
        nd -= g;
      }
      if (t + d < 10) {
        int g = min(nd, c[t + d]);
        rs += g * d;
        nd -= g;
      }
    }
    nd = max(0, K - c[t]);
    string str = s;
    FOR(d, 1, 10) {
      vc<int> st;
      if (t + d < 10) {
        st.insert(ed(st), all(v[t + d]));
      }
      if (t - d >= 0) {
        int sz = si(st);
        st.insert(ed(st), all(v[t - d]));
        reverse(bg(st) + sz, ed(st));
      }
      if (si(st) > nd) sh(st, nd);
      nd -= si(st);
      for (int x : st) str[x] = t;
    }
    FOR(i, N) str[i] += '0';
    return {rs, str};
  };
  pair<int, string> rs{inf<int>, {}};
  FOR(i, 10) chmin(rs, get(i));
  print(rs.fi);
  print(rs.se);
}

int main() {
  Yorisou();
  return 0;
}