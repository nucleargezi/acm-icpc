#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  vc<PII> a(K);
  FOR(i, K) IN(a[i].fi);
  FOR(i, K) IN(a[i].se);
  for (var [a, b] : a) if (a < b) return NO();
  FOR(t, K - 1) {
    var [i, c] = a[t];
    var [k, d] = a[t + 1];
    if (k - i < d - c) return NO();
  }
  string s = "abc";
  int sz = 3, c = 3, tr = 0, t = 3;
  for (var [i, w] : a) {
    while (c < w) ++sz, ++c, s += char('a' + t);
    ++t;
    while (sz < i) ++sz, s += char('a' + tr), tr = (tr + 1) % 3;
  }
  YES();
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}