#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/presum_add.hpp"

constexpr int p0 = 167'772'161;
constexpr int p1 = 469'762'049;
constexpr int p2 = 754'974'721;

using MX0 = Presum_add<mint_t<p0>, 3>;
using MX1 = Presum_add<mint_t<p1>, 3>;
using MX2 = Presum_add<mint_t<p2>, 3>;

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
  segl_t<MX0> s0(N - 1, [&](int i) { return MX0::X(i, 0); });
  segl_t<MX1> s1(N - 1, [&](int i) { return MX1::X(i, 0); });
  segl_t<MX2> s2(N - 1, [&](int i) { return MX2::X(i, 0); });

  FOR(Q) {
    CH(op);
    INT(l, r);
    --l, --r;
    if (op == 'C') {
      LL(v);
      s0.apply(l, r, v);
      s1.apply(l, r, v);
      s2.apply(l, r, v);
    } else {
      Z get = [&](Z &seg) -> ull {
        Z x = seg.prod(l, r);
        return (-x.s[2] * 2 + x.s[1] * (l + r - 2) + x.s[0] * ll(r) * (1 - l)).val();
      };

      ull a = crt(get(s0), get(s1), get(s2));
      ull b = ull(r - l + 1) * (r - l) / 2;
      ull g = gcd(a, b);
      put(a / g, '/', b / g, '\n');
    }
  }
}

int main() { Yorisou(); }