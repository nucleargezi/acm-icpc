#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/line/01/vec_sp.hpp"

using mint = mint_t<10086>;
void Yorisou() {
  INT(N);
  vec_sp<int, 30> s;
  FOR(i, N) {
    INT(x);
    s.add(x);
  }
  INT(x);
  print(mint(2).pow(N - si(s)) * s.rank(x) + 1);
}

int main() {
  Yorisou();
  return 0;
}