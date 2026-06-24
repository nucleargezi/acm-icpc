#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/many_lcs.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> a;
  FOR(i, N) {
    INT(sz);
    VEC(int, v, sz);
    FOR_R(i, sz - 1) v[i + 1] -= v[i];
    v.erase(bg(v));
    a.ep(v);
  }
  print(si(lcs(a)) + 1);
}

int main() {
  Yorisou();
  return 0;
}