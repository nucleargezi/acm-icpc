#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/random/hash.hpp"

void Yorisou() {
  int n;
  vc<ull> v{1, 2}, ps;
  for (;;) {
    ull a = v.end()[-2], b = v.end()[-1];
    if (a + b > 1'000'000'000'000'000'000ull) break;
    v.ep(a + b);
  }
  n = si(v);
  ps = pre_sum<0>(v);
  
  hashmap<ull> me(1 << 12);
  using T = pair<ull, ull>;
  Z f = [&](Z &f, ull x, int n) -> ull {
    if (x == 0) return 1;
    if (n < 0 or x < 0 or x > ps[n]) return 0;
    ull hs = hsh(T{x, n});
    if (me.contains(hs)) return me[hs];
    return me[hs] = f(f, x, n - 1) + f(f, x - v[n], n - 1);
  };
  LL(N);
  print(f(f, N, n - 1));
}

int main() {
  Yorisou();
  return 0;
}