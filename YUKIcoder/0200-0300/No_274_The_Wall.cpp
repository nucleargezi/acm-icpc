#include "YRS/all.hpp"

void Yorisou() {
  INT(N, S);
  vc<u16> c(S + 1);
  vc<u16> ms(S + 1);
  FOR(N) {
    INT(l, r);
    ++r;
    int ll = S - r, rr = S - l;
    if (ll < l) swap(ll, l), swap(rr, r);
    if (r <= ll) {
      c[l] += 1, c[r] -= 1;
    } else {
      ms[ll] += 1, ms[r] -= 1;
      c[l] += 1, c[ll] -= 1;
      c[r] += 1, c[rr] -= 1;
    }
  }
  FOR(i, S) c[i + 1] += c[i];
  FOR(i, S) if (c[i] > 2) return NO();
  FOR(i, S) ms[i + 1] += ms[i];
  FOR(i, S) if (ms[i] > 1) return NO();
  YES();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"