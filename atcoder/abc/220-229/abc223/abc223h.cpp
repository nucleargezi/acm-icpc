#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/line/01/range_sp_offline.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  vc<PII> q(Q);
  vc<ll> ck(Q);
  FOR(i, Q) {
    IN(q[i].fi, q[i].se, ck[i]);
    --q[i].fi;
  }
  vc<char> rs(Q);
  range_sp_offline<ll, 60>(a, q).run([&](int i, var bs) {
    ll x = ck[i];
    for (ll f : bs) chmin(x, x ^ f);
    rs[i] = x == 0;
  });
  FOR(i, Q) Yes(rs[i]);
}

int main() { Yorisou(); }