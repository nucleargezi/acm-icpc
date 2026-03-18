#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/seg/segl_sparse_t.hpp"
#include "YRS/al/am/sum_affine.hpp"

using AM = a_monoid_sum_affine<ull>;
using MX = AM::MX;
using MA = AM::MA;
using DS = segl_sprase_t<AM>;
constexpr ull mod = 1'000'000'000'000'000'000ull + 9;
void Yorisou() {
  LL(N, Q);
  VEC(T3<ll>, q, Q);
  vc<ull> f;
  for (Z &[x, l, r] : q) {
    ++r;
    f.ep(l);
    f.ep(r);
  }
  f.ep(0);
  f.ep(N);
  unique(f);
  
  DS seg[5];
  FOR(i, 5) seg[i] = DS(f);
  array<ull, 5> s{};
  for (Z &&[x, l, r] : q) {
    if (x == 0) {
      ull g[5]{};
      FOR(i, 5) g[i] = seg[i].prod(l, r);
      ull mx = QMAX(g, g + 5);
      int c = 0, id = -1;
      FOR(i, 5) if (mx == g[i]) {
        ++c, id = i;
      }
      if (c == 1) {
        s[id] += mx;
        if (s[id] >= mod) s[id] -= mod;
      }
    } else {
      --x;
      FOR(i, 5) {
        if (i == x) {
          seg[i].apply(l, r, MA::make_add(1));
        } else {
          seg[i].apply(l, r, MA::make_mul(0));
        }
      }
    }
  }
  FOR(i, 5) s[i] += seg[i].prod(0, N), s[i] %= mod;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"