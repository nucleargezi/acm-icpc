#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add_array.hpp"

constexpr int p0 = 167'772'161, p1 = 469'762'049, p2 = 754'974'721;
using MX0 = Add_arr<mint_t<p0>, 2>;
using MX1 = Add_arr<mint_t<p1>, 2>;
using MX2 = Add_arr<mint_t<p2>, 2>;
using DS0 = bit_t<MX0>;
using DS1 = bit_t<MX1>;
using DS2 = bit_t<MX2>;
ull crt(ull a, ull b, ull c) {
  constexpr ull x = 104'391'568, xx = 190'329'765;
  ull t = (b - a + p1) * x % p1, s = a + t * p0;
  t = (c - s % p2 + p2) * xx % p2;
  return ull(s) + ull(t) * ull(ull(p0) * p1);
}
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS0 bit0(N);
  DS1 bit1(N);
  DS2 bit2(N);
  FOR(i, N) bit0.multiply(i, MX0::add(i, a[i]));
  FOR(i, N) bit1.multiply(i, MX1::add(i, a[i]));
  FOR(i, N) bit2.multiply(i, MX2::add(i, a[i]));

  FOR(Q) {
    STR(op);
    if (op[0] == 'Q') {
      INT(x);
      ull a = MX0::eval(bit0.prod(x), x).val();
      ull b = MX1::eval(bit1.prod(x), x).val();
      ull c = MX2::eval(bit2.prod(x), x).val();
      print(crt(a, b, c));
    } else {
      INT(i, x);
      --i;
      Z d = -a[i] + x;
      a[i] = x;
      bit0.multiply(i, MX0::add(i, d));
      bit1.multiply(i, MX1::add(i, d));
      bit2.multiply(i, MX2::add(i, d));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}