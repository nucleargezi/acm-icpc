#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/add.hpp"

using mint = M11;
void Yorisou() {
  INT(N, M);
  VEC(PII, es, M);
  sort(es, [&](PII a, PII b) { return a.se < b.se; });

  seg_t<Add<mint>> seg(M + 1);
  seg.set(0, 1);
  mint res;
  FOR(i, M) {
    var [l, r] = es[i];
    int ls = bina([&](int i) {
      return es[i].se >= l;
    }, i, -1) + 1;
    if (l == 0) --ls;
    int rs = bina([&](int i) {
      if (i == -1) return true;
      return es[i].se < r;
    }, -1, i) + 1;
    seg.set(i + 1, seg.prod(ls, rs + 1));
    if (r == N) res += seg.get(i + 1);
  }
  print(res);
}

int main() {
  Yorisou();
  return 0;
}