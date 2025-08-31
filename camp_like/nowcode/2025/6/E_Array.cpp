#include "MeIoN_Lib/Z_H/MeioN.hpp"
// #include "MeIoN_Lib/"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
constexpr int B = 660, N = 1'000'00, bsz = 152;
vector<int> v[bsz];
ll val[bsz];
int go[bsz][N + 1];
void Yorisou() {
  INT(n, q);
  VEC(int, a, n);
  for (int &x : a) --x;
  
  vector<T4<int>> quis;
  quis.reserve(q);
  int c = 0, cc = 0;
  for (int i = 0, op, l, r, x; i < q; ++i) {
    IN(op);
    if (op == 1) {
      ++c;
      IN(l, r, x);
    } else {
      ++cc;
      IN(l, r);
    }
    quis.emplace_back(op, l, r, x);
  }
  
  chmax(c, 1), chmax(cc, 1);
  const int B = std::max(660, int(std::sqrt(c * n / (cc * (topbit(n) + 1))) + 0.5)), N = n,
            bsz = ceil(n, B);
  for (int i = 0; i < n; ++i) {
    v[i / B].emplace_back(a[i]);
  }
  for (int i = 0; i < bsz; ++i) {
    sort(v[i]);
    int sz = len(v[i]);
    for (int x = 0, p = 0; x < n + 1; ++x) {
      while (p < sz and v[i][p] < x) ++p;
      go[i][x] = p;
    }
  }
  fenw<monoid_add<ll>> seg(n + 1);
 
  ll ans = 0;
  for (int i =0 ; i < q; ++i) {
    meion [op, l, r, x] = quis[i];
    l ^= ans, r ^= ans, x ^= ans;
    if (l > r) swap(l, r);
    if (op == 1) {
      --l;
      seg.multiply(l, x), seg.multiply(r, -x);
      for (int i = 0; i < bsz; ++i) {
        assert(len(v[i]));
        if (l > v[i].back() or r <= v[i][0]) continue;
        val[i] += ll(go[i][r] - go[i][l]) * x;
      }
    } else {
      ans = 0;
      --l, --r;
      int li = l / B, ri = r / B;
      if (li == ri) {
        for (int i = l; i < r + 1; ++i) ans += seg.prod(a[i] + 1);
      } else {
        int e = l / B * B + B;
        for (int i = l; i < e; ++i) {
          ans += seg.prod(a[i] + 1);
        }
        for (int i = r / B * B; i < r + 1; ++i) {
          ans += seg.prod(a[i] + 1);
        }
        for (int i = li + 1; i < ri; ++i) {
          ans += val[i];
        }
      }
      UL(ans);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"