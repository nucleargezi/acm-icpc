#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  INT(N, K, A);
  vc<int> b(N), c(N);
  FOR(i, N) IN(b[i], c[i]);
  re s = 0;
  Z ck = [&](const vc<int> &se) -> void {
    vc<int> cc = c;
    for (int x : se) cc[x] += 10, chmin(cc[x], 100);
    re rs = 0;
    FOR(s, 1 << N) {
      re c = 1;
      FOR(i, N) {
        if (s >> i & 1) c *= cc[i] / 100.l;
        else c *= 1.l - cc[i] / 100.l;
      }
      if (2 * pc(s) > N) {
        rs += c;
      } else {
        int B = 0;
        FOR(i, N) if (~s >> i & 1) B += b[i];
        rs += c * A / (A + B);
      }
    }
    chmax(s, rs);
  };
  vc<int> se;
  Z f = [&](Z &f, int t, int p) -> void {
    if (t == K) return ck(se);
    FOR(i, p, N) se.ep(i), f(f, t + 1, i), pop(se);
  };
  f(f, 0, 0);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}