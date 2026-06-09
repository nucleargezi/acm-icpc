#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/hs.hpp"

void Yorisou() {
  STR(str, s, t);
  hash_t hs(str);
  Z ss = hsh(s), tt = hsh(t);
  int N = si(str), n = si(s), m = si(t);
  vc<ll> a(N), b(N);
  FOR(i, N - n + 1) a[i] = hs.get(i, i + n) == ss;
  FOR(i, N - m + 1) b[i + m - 1] = hs.get(i, i + m) == tt;
  vc<ull> rs;
  n = max(n, m);
  FOR(i, N) FOR(k, i + n - 1, N) {
    if (a[i] and b[k]) {
      rs.ep(hs.get(i, k + 1).se);
    }
  }
  unique(rs);
  print(si(rs));
}

int main() {
  Yorisou();
  return 0;
}