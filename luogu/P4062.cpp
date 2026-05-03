#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/enum_density_range.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, t);
  VEC(int, a, N);
  vc<vc<int>> v(N);
  FOR(i, N) v[a[i]].ep(i);
  bit_t<monoid_add<int>> bit(N << 1 | 1);
  ll s = 0;
  vc<u8> vis(N << 1 | 1);
  vc<int> del;
  del.reserve(N);
  FOR(x, N) for (Z [l, r] : enum_density_range(2, v[x])) {
    chmax(l, 0);
    chmin(r, N);
    int of = N;
    del.clear();
    del.ep(of);
    vis[of] = 1;
    bit.multiply(of, 1);
    FOR(i, l, r) {
      if (a[i] == x) ++of;
      else --of;
      s += bit.prod(of);
      if (not vis[of]) vis[of] = 1, del.ep(of);
      bit.multiply(of, 1);
    }
    for (int x : del) vis[x] = 0, bit.set(x, 0);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}