#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/static_range_prod.hpp"
#include "YRS/ds/monoid/min.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    int s, lmin;
  };
  static constexpr X unit() { return {0, 0}; }
  static X op(const X &L, const X &R) {
    int s = L.s + R.s;
    int lmin = min(L.lmin, L.s + R.lmin);
    return {s, lmin};
  }
};
vc<int> go(const vc<int> &a) {
  int N = len(a);
  vc<int> res(N, -1);
  static_range_prod<MX> st(N, [&](int i) -> MX::X { return {a[i], a[i]}; });
  FOR(i, N) if (a[i] == 1) {
    res[i] = st.max_right([&](MX::X x) -> bool {
      return x.lmin >= 0;
    }, i) - i;
  }
  return res;
}
void Yorisou() {
  INT(N);
  vc<int> s;
  FOR(N) {
    CH(c);
    s.ep(c == 'p' ? 1 : -1);
  }
  vc<int> L = go(s);
  reverse(all(s));
  vc<int> R = go(s);
  reverse(all(R));
  FOR(i, N) {
    if (R[i] == -1) R[i] = N;
    else R[i] = i - R[i];
  }

  int ans = 0;
  static_range_prod<monoid_min<int>> st(R);
  FOR(i, N) if (L[i] != -1) {
    int r = bina([&](int l) -> bool {
      return st.prod(l, i + L[i]) < i;
    }, i, i + L[i]);
    chmax(ans, min(r - i + 1, L[i]));
  }
  print(ans);
}
#include "YRS/aa/main.hpp"