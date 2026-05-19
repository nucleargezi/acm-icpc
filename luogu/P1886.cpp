#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/swag.hpp"
#include "YRS/al/m/minmax.hpp"

void Yorisou() {
  INT(N, K);
  swag_queue<Minmax<int>> q;
  vc<PII> rs;
  FOR(i, N) {
    INT(x);
    q.ep(x, x);
    if (si(q) >= K) rs.ep(q.prod()), q.pop();
  }
  FOR(i, N - K + 1) put(rs[i].fi, " \n"[i == N - K]);
  FOR(i, N - K + 1) put(rs[i].se, " \n"[i == N - K]);
}

int main() {
  Yorisou();
  return 0;
}