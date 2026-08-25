#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/bass_cnt.hpp"
#include "YRS/al/m/add.hpp"

using MX = Add<ll>;
void Yorisou() {
  INT(N, M, Q);
  STR(s);
  bass g(s);
  vc<pair<PII, ll>> dat(M);
  FOR(i, M) {
    INT(l, r);
    --l;
    dat[i] = {{l, r}, 1};
  }
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : bass_cnt<MX, 26>(g, move(dat), move(q))) print(x);
}

int main() { Yorisou(); }