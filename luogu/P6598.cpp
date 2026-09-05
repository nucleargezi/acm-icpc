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
  const T i2 = invs(2), i6 = invs(6), i24 = invs(24);
  Z f = ofps<T>(
    [&](Z a, Z r, Z v, Z w) {
      return 1 + shift<1>((a * a * a + a * at_pow<2>(a) * 3 + at_pow<3>(a) * 2) * i6);
    },
    [](Z a, Z r, Z v, Z w) {
      return a - 1;
    },
    [&](Z a, Z r, Z v, Z w) {
      return shift<1>((a * a * a * a + a * a * at_pow<2>(a) * 6
        + at_pow<2>(a) * at_pow<2>(a) * 3 + a * at_pow<3>(a) * 8
        + at_pow<4>(a) * 6) * i24);
    },
    [&](Z a, Z r, Z v, Z w) {
      return v - (r * r - at_pow<2>(r)) * i2;
    }
  );
  print(f.get<3>()[N]);
}

int main() { Yorisou(); }