#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/range_dis_substr.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  range_dis_substr ss(s);
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    ss.add(l, r);
  }
  for (ll x : ss.slv()) print(x);
}

int main() {
  Yorisou();
  return 0;
}