#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
void Yorisou() {
  INT(N, M);
  retsu<char> a(N, M);
  FOR(i, N) FOR(k, M) {
    CH(c);
    if (c == '?') a[i][k] = -1;
    else a[i][k] = c - '0';
  }
  
  Z ok = [&](char *a, int n, int s) {
    FOR(i, n) if (a[i] == (s ^ (i & 1))) return 0;
    return 1;
  };
  Z ke = [&]() -> mint {
    int n = a.N, m = a.M;
    mint s = 1;
    FOR(i, n) s *= ok(a[i], m, 0) + ok(a[i], m, 1);
    return s;
  };

  mint s = ke();
  a = a.rol90();
  s += ke();

  Z ck = [&](int s) {
    int n = a.N, m = a.M;
    FOR(i, n) if (not ok(a[i], m, s ^ (i & 1))) return 0;
    return 1;
  };

  s -= ck(0) + ck(1);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"