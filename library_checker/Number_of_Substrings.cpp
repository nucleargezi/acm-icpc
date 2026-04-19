#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/SA.hpp"

void Yorisou() {
  STR(s);
  ll rs = si(s);
  rs = rs * (rs + 1) / 2;
  SA sa(s);
  rs -= SUM<ll>(sa.lcp);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}