#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add_array.hpp"

using mint = M99;
using MX = Add_arr<mint, 3>;
using DS = bit_t<MX>;
void Yorisou() {
  INT(N, Q);
  vc<mint> v(N);
  DS bit(N);
  Z set = [&](int i, mint x) {
    mint d = x - v[i];
    v[i] = x;
    x = d;
    bit.multiply(i, MX::add(i, x));
  };
  FOR(i, N) {
    INT(x);
    set(i, x);
  }
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      set(i, x);
    } else {
      INT(i);
      print(MX::eval(bit.prod(i), i));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}