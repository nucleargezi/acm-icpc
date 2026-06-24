#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ds/range/range_brac.hpp"

void Yorisou() {
  STR(a, b);
  range_brac ds(b);
  for (char &c : a) c = c == '(' ? 0 : 1;
  for (char &c : b) c = c == '(' ? 0 : 1;
  sam<2> ss(si(a));
  ss.build(a);
  vc<int> sl = ss.run(b);
  int n = si(b), rs = 0;
  FOR(i, n) chmax(rs, ds.prod(i - sl[i] + 1, i + 1));
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}