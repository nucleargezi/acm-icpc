#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"

constexpr int sz = 3'000'2, B = 1 << 12, O = 3;
using X = bitset<sz>;
void Yorisou() {
  INT(N, Q, f);
  VEC(int, a, N);
  graph g(N);
  g.sc();
  hld v(g);
  vc<X> sa(ceil(N, B)), sb(ceil(N, B >> O));
  for (Z &x : sa) x.set();
  for (Z &x : sb) x.set();
  a = rearrange(a, v.V);
  FOR(i, N) sa[i / B].reset(a[i]);
  FOR(i, N) sb[i / (B >> O)].reset(a[i]);
  
  int ls = 0;
  FOR(Q) {
    INT(k);
    static X s;
    s.set();
    FOR(k) {
      INT(x, y);
      x ^= ls, y ^= ls;
      --x, --y;
      for (Z [l, r] : v.dec(x, y, 0)) {
        if (l > r) swap(l, r);
        ++r;
        while (l < r and l % (B >> O)) s.reset(a[l++]);
        while (l < r and r % (B >> O)) s.reset(a[--r]);
        while (l < r and l % B) s &= sb[l / (B >> O)], l += (B >> O);
        while (l < r and r % B) r -= (B >> O), s &= sb[r / (B >> O)];
        l /= B, r /= B;
        FOR(i, l, r) s &= sa[i];
      }
    }
    int x = sz - s.count(), y = s._Find_first();
    print(x, y);
    if (f) ls = x + y;
  }
}

int main() {
  Yorisou();
  return 0;
}