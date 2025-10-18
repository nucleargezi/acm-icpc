#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  LL(a, b, c, d, v, t);
  ll g = std::gcd(a, c);
  ll aa = a / g, c_c = c / g, vv = v / g, l = a / g * c;
  ll ca = t / a + 1, cc = t / c + 1, cl = t / l + 1;
  ll s = ca + cc - cl;

  ll L = aa * c_c;
  vector<int> pr{0};
  int cs = 0;
  ll x = 0, na = aa, nc = c_c;
  while (x < L) {
    ll y = std::min(na, nc), g = y - x;
    if (g < vv + 1) ++cs;
    pr.ep(cs);
    x = y;
    if (na == y) na += aa;
    if (nc == y) nc += c_c;
  }
  int sz = len(pr) - 1;
  ll tt = std::max(0ll, s - 1);
  ll el = pr[sz] * (sz ? tt / sz : 0) + (sz ? pr[sz ? tt % sz : 0] : 0);
  i128 cu = i128(b) * ca + i128(d) * cc;
  print(cu - s + el);
}
#include "YRS/Z_H/main.hpp"