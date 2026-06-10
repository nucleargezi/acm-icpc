#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  multiset<PII> se;
  FOR(N) {
    INT(a, b);
    se.eb(a, -b);
  }
  ll s = 0;
  while (si(se)) {
    Z [a, b] = *bg(se);
    se.extract(bg(se));
    ll c = 1;
    s -= b;
    while (si(se)) {
      Z it = se.lower_bound({a + 1, -inf<int>});
      if (it == ed(se) or it->fi != a + 1) break;
      ++a;
      ++c;
      s -= it->se * c;
      se.extract(it);
    }
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}