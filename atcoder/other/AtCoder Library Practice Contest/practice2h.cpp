#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/two_sat.hpp"

void Yorisou() {
  INT(N, D);
  sat g(N);
  vc<array<int, 2>> s(N);
  IN(s);
  FOR(i, N) FOR(k, i + 1, N) FOR(a, 2) FOR(b, 2) {
    if (abs(s[i][a] - s[k][b]) < D) g.ban(i, k, a, b);
  }
  if (g.slv()) {
    Yes();
    Z vs = g();
    FOR(i, N) print(s[i][vs[i]]);
  } else {
    No();
  }
}

int main() {
  Yorisou();
  return 0;
}