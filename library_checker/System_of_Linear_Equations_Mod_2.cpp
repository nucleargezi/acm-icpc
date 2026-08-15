#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/gauss.hpp"

void Yorisou() {
  INT(N, M);
  vc<bs> a(N);
  FOR(i, N) {
    STR(s);
    a[i] = s;
  }
  bs b;
  STR(s);
  b = s;
  Z rs = solve_linear(M, a, b);
  if (rs.empty()) {
    print(-1);
  } else {
    print(si(rs) - 1);
    FOR(i, si(rs)) print(rs[i]);
  }
}

int main() {
  Yorisou();
  return 0;
}