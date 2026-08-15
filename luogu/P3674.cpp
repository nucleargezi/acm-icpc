#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/bs.hpp"
#include "YRS/ds/mo/mo.hpp"

using BS = bs;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<PII> q(Q), qq(Q);
  FOR(i, Q) IN(q[i].fi, qq[i], q[i].se), --qq[i].fi;

  int sz = QMAX(a) + 1;
  BS bs(sz), rbs(sz << 1);
  vc<int> c(sz);
  Z ad = [&](int i) {
    int x = a[i];
    if (not c[x]++) bs.set(x), rbs.set(sz - x);
  };
  Z rm = [&](int i) {
    int x = a[i];
    if (not --c[x]) bs.reset(x), rbs.reset(sz - x);
  };

  vc<char> rs(Q);
  mo(qq, ad, ad, rm, rm, [&](int i) {
    var [op, x] = q[i];
    if (op == 1) {
      if (x == 0) {
        rs[i] = 1;
      } else {
        rs[i] = (bs & (bs << x)).any();
      }
    } else if (op == 2) {
      rs[i] = ((rbs << x).range(sz, sz << 1) & bs).any();
    } else {
      for (int e = 1; e * e <= x and e < sz; ++e) if (x % e == 0 and x / e < sz) {
        if (bs[e] and bs[x / e]) {
          rs[i] = 1;
          break;
        }
      }
    }
  });
  FOR(i, Q) print(rs[i] ? "hana" : "bi");
}

int main() {
  Yorisou();
  return 0;
}