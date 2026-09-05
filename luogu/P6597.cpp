#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/ofps/online_ctx.hpp"

using mint = M99;
using namespace online;

TP <int K, expr F> struct at_xk : online_src<typename F::value_type, at_xk<K, F>> {
  using T = typename F::value_type;
  static constexpr bool fixed = F::fixed;
  F f;
  at_xk(F g) : f(move(g)) {}
  T operator[](int i) { return i % K ? T() : f[i / K]; }
  bool ready(int i) { return i % K or f.ready(i / K); }
  int lo() requires(fixed) { return f.lo() * K; }
  int hi() requires(fixed) { return f.lo() == f.hi() ? 0 : (f.hi() - 1) * K + 1; }
};

TP <int K, expr F> Z at_pow(F f) { return at_xk<K, F>(move(f)); }

void Yorisou() {
  INT(N);
  const mint i2 = invs(2), i6 = invs(6);
  Z f = ofps<mint>(
    [=](Z a, Z b, Z c) {
      return 1 + shift<1>((a * a * a + a * at_pow<2>(a) * 3 + at_pow<3>(a) * 2) * i6);
    },
    [=](Z a, Z b, Z c) {
      return shift<1>((a * a + at_pow<2>(a)) * i2);
    },
    [=](Z a, Z b, Z c) {
      return (b * b + at_pow<2>(b)) * i2;
    }
  );
  FOR(i, 2, N + 1) print(f.get<2>()[i]);
}

int main() { Yorisou(); }