#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  vc<PII> a(N);
  FOR(i, N) {
    STR(s);
    int c = 0, m = 0;
    for (char x : s) {
      c += x == ')' ? -1 : 1;
      chmin(m, c);
    }
    a[i] = {m, c};
  }
  sort(a, [](PII a, PII b) {
    if ((a.se >= 0) != (b.se >= 0)) return a.se >= 0;
    return a.se >= 0 ? a.fi > b.fi : a.se - a.fi > b.se - b.fi;
  });
  ll s = 0;
  for (var [m, c] : a) {
    if (s + m < 0) return No();
    s += c;
  }
  Yes(s == 0);
}

int main() { Yorisou(); }