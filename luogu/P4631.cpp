#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/kdt/kdt.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<int>, c, N);
  vc<T3<int>> a(N);
  FOR(i, N) {
    var [x, y, r] = c[i];
    a[i] = {x, y, i};
  }

  vc<int> I(N);
  iota(all(I), 0);
  sort(I, [&](int i, int k) {
    if (get<2>(c[i]) != get<2>(c[k])) return get<2>(c[i]) > get<2>(c[k]);
    return i < k;
  });
  kdt ds(all(a));
  vc<int> rs(N, -1);
  for (int i : I) if (rs[i] == -1) {
    rs[i] = i + 1;
    var [x, y, r] = c[i];
    ds.enum_k_C(x, y, r << 1, [&](int k) {
      if (rs[k] == -1) {
        var [xx, yy, rr] = c[k];
        ll dx = x - xx, dy = y - yy, sr = r + rr;
        if (dx * dx + dy * dy <= sr * sr) rs[k] = i + 1;
      }
    });
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}