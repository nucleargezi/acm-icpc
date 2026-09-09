#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom_sum_off.hpp"

using T = M11;

void Yorisou() {
  INT(l, c, r, d);
  T s;
  vc<PII> q;
  q.reserve(((r - l + d - c + 2) << 1));
  FOR(i, l + c, r + d + 1) {
    int ls = c, rs = d;
    chmax(ls, i - r);
    chmin(rs, i - l);
    q.ep(i, rs + 1);
    q.ep(i, ls);
  }
  Z f = binom_sum_off<T>(q);
  FOR(i, si(f)) {
    if (i & 1) s -= f[i];
    else s += f[i];
  }
  print(s);
}

int main() { Yorisou(); }