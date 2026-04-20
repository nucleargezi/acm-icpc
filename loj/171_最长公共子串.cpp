#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/hs.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N);
  VEC(string, s, N);
  int r = inf<int>;
  FOR(i, N) chmin(r, si(s[i]));
  vc<hash_t> hs(N);
  FOR(i, N) hs[i] = hash_t(s[i]);
  print(bina([&](int sz) -> bool {
    if (sz == 0) return 1;
    hashmap<u8> a, b;
    FOR(i, N) {
      b.clear();
      int n = si(s[i]);
      FOR(k, n - sz + 1) {
        b[hs[i].get(k, k + sz).se.val()] = 1;
      }
      for (Z x : b.get_all()) ++a[x.fi];
    }
    for (Z x : a.get_all()) if (x.se == N) return 1;
    return 0;
  }, 0, r + 1));
}

int main() {
  Yorisou();
  return 0;
}