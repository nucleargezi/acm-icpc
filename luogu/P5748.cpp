#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/bell.hpp"

using mint = M99;
void Yorisou() {
  INT(Q);
  Z f = bell<mint>(1'000'00);
  FOR(Q) {
    INT(x);
    print(f[x]);
  }
}

int main() { Yorisou(); }