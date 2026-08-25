#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/bass.hpp"
#include "YRS/al/m/add.hpp"

using MX = Add<ll>;
void Yorisou() {
  INT(N);
  STR(s);
  for (char &c : s) c -= 'a';
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  bass g(s);
  for (ll x : g.count_offline_src<MX>({}, {}, {}, 1, move(q))) print(x);
}

int main() { Yorisou(); }