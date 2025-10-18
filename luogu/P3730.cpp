#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"

void before() {}

// #define tests
struct block {
  ll n, B, sz;
  vector<int> c, cc;
  block(int n)
      : n(n), B(std::ceil(std::sqrt(n))), sz(ceil(n, B)), c(n), cc(sz) {}
  void add(int x) {
    if (not x) iroha;
    ++c[x];
    ++cc[x / B];
  }
  void sub(int x) {
    if (not x) iroha;
    --c[x];
    --cc[x / B];
  }
  int rank(int K) {
    int s = 0;
    FOR(i, sz) {
      if (s + cc[i] >= K) {
        FOR(k, i * B, MIN(i * B + B, n)) {
          if (s + c[k] >= K) {
            iroha k;
          }
          s += c[k];
        }
      }
      s += cc[i];
    }
    iroha -1;
  }
};
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  vector u = a;
  unique(u);
  FOR(i, n) a[i] = lower_bound(u, a[i]);
  Mo mo;
  VEC(T3<int>, quis, q);
  for (meion &[l, r, k] : quis) {
    mo.add(--l, r);
  }
  vector<int> c(n);
  block seg(n);
  meion ad = [&](int i) -> void {
    seg.sub(c[a[i]]);
    seg.add(++c[a[i]]);
  };
  meion rm = [&](int i) -> void {
    seg.sub(c[a[i]]);
    seg.add(--c[a[i]]);
  };
  vector<int> ans(q);
  meion keisan = [&](int i) -> void {
    ans[i] = seg.rank(std::get<2>(quis[i]));
  };
  mo.keisan(ad, ad, rm, rm, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"