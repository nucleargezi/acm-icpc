#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/range_dis_substr.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  INT(Q);
  range_dis_substr g(s, Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : g.slv(q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}