#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/bass_cnt.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(M, Q);
  string s, t;
  IN(s);
  vc<pair<PII, ll>> dat(M);
  FOR(i, M) {
    IN(t);
    int l = si(s), r = l + si(t);
    s += t;
    dat[i] = {{l, r}, 1};
  }
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  print(bass_cnt<Add<ll>>(bass(s), move(dat), move(q)));
}

int main() { Yorisou(); } 