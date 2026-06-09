#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/hs.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  hash_t hs(s);
  
  Z ok = [&](int l, int r) -> bool {
    FOR(i, l, r) if (s[i] != '4' and s[i] != '7') return 0;
    return 1;
  };
  
  Z ke = [&](int l, int r) -> int {
    Z hsh = hs(l, r);
    int c = 0;
    FOR(i, N - r + l + 1) c += hs(i, i + r - l) == hsh;
    return c;
  };

  using T = pair<int, string>;
  T rs{1, {}};
  FOR(l, N) FOR(r, l + 1, N + 1) if (ok(l, r)) {
    chmin(rs, T(-ke(l, r), s.substr(l, r - l)));
  }
  if (rs.fi == 1) print(-1);
  else print(rs.se);
}

int main() {
  Yorisou();
  return 0;
}