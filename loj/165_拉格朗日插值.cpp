#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/poly/lag_t.hpp"

using mint = M99;
void Yorisou() {
  INT(Q);
  lag_t<mint> f;
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(a, b);
      f.add(a, b);
    } else {
      INT(i);
      print(f(i));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}