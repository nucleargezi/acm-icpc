#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/segd_sprase_t.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    int c;
    ll s;
  };
  static constexpr X unit() { return {0, 0}; }
  static constexpr X op(const X &L, const X &R) {
    return {L.c + R.c, L.s + R.s};
  }
  static constexpr bool commute = true;
};
using X = MX::X;
X sing(int x, int c = 0) { return {c, ll(x) * c}; }
using DS = segd_sprase_t<MX>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  vc<int> a(N);
  vc<X> dat(N);
  FOR(i, N) dat[i] = sing(0, 1);
  DS ds(0, 1'000'000'000);
  np t = nullptr;
  t = ds.multiply(t, 0, sing(0, N));
  FOR(Q) {
    CH(op);
    if (op == 'U') {
      INT(k, w);
      --k;
      t = ds.multiply(t, a[k], {-1, -a[k]});
      a[k] = w;
      t = ds.multiply(t, a[k], {1, a[k]});
    } else {
      INT(c, s);
      Z [cnt, sum] = ds.prod(t, 0, s);
      ll sm = sum + ll(N - cnt) * s;
      TAK(sm >= 1ll * c * s);
    }
  }
}
#include "YRS/aa/main.hpp"