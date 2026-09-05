#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/presum_add.hpp"

constexpr int p0 = 167'772'161;
constexpr int p1 = 469'762'049;
constexpr int p2 = 754'974'721;

using MX0 = Presum_add<mint_t<p0>, 2>;
using MX1 = Presum_add<mint_t<p1>, 2>;
using MX2 = Presum_add<mint_t<p2>, 2>;

ull crt(ull a, ull b, ull c) {
  constexpr ull x = 104'391'568;
  constexpr ull xx = 190'329'765;
  ull t = (b - a + p1) * x % p1;
  ull s = a + t * p0;
  t = (c - s % p2 + p2) * xx % p2;
  return s + t * ull(p0) * p1;
}

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);

  segl_t<MX0> s0(N, [&](int i) { return MX0::X(i, a[i]); });
  segl_t<MX1> s1(N, [&](int i) { return MX1::X(i, a[i]); });
  segl_t<MX2> s2(N, [&](int i) { return MX2::X(i, a[i]); });

  FOR(Q) {
    STR(op);
    if (op[0] == 'Q') {
      INT(x);
      ull a = s0.prod(0, x)(x).val();
      ull b = s1.prod(0, x)(x).val();
      ull c = s2.prod(0, x)(x).val();
      print(crt(a, b, c));
    } else {
      INT(i);
      LL(x);
      --i;
      ll d = x - a[i];
      a[i] = x;
      s0.apply(i, i + 1, d);
      s1.apply(i, i + 1, d);
      s2.apply(i, i + 1, d);
    }
  }
}

int main() { Yorisou(); }