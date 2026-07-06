#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int f(int x) {
  string s(to_string(x));
  int rs = 0;
  for (char c : s) chmax(rs, c - '0');
  return rs;
}

void Yorisou() {
  LL(l, r);
  int mx = -1;
  FOR(i, l, min(r + 1, l + 10)) chmax(mx, f(i));
  if (r - l <= 20) {
    string rs{char('9' + 1)};
    FOR(i, l, r + 1) {
      if (f(i) == mx) chmin(rs, to_string(i));
    }
    return print(mx, rs);
  }

  string s{char('9' + 1)};
  int n = si(to_string(l)), m = si(to_string(r));
  string t;
  Z ok = [&](var s) {
    ll x = stoll(s);
    return x >= l;
  };
  Z upd = [&](var t) {
    bool f = 0;
    for (char c : t) f |= c == mx + '0';
    if (not f) return;
    ll x = stoll(t);
    if (x <= r) chmin(s, t);
  };

  FOR(sz, n, m + 1) {
    t = string(sz, mx + '0');
    FOR_R(i, 1, 10) {
      t[0] = i + '0';
      if (ok(t)) upd(t);
      else {
        ++t[0];
        break;
      }
    }
    FOR(k, 1, sz + 1) FOR_R(i, 10) {
      t[k] = i + '0';
      if (ok(t)) upd(t);
      else {
        ++t[k];
        break;
      }
    }
  }
  print(mx, s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}