#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_add.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, v, n);
  FOR(i, n) --v[i];
  vector<int> L(n), R(n), c(n);
  FOR(i, n) {
    L[i] = not c[v[i]]++;
  }
  L = pre_sum(L);
  fill(c, 0);
  FOR_R(i, n) {
    R[i] = not c[v[i]]++;
  }
  R += 0;
  FOR_R(i, n) R[i] += R[i + 1];
  lazy_seg<a_monoid_max_add<int>> seg(n + 1);
  vector<int> nxt(n, n);
  int ans{};
  FOR_R(i, n) {
    seg.apply(i, R[i]);
    seg.apply(i + 1, nxt[v[i]] + 1, 1);
    nxt[v[i]] = i;
    chmax(ans, L[i] + seg.prod(0, n + 1));
  }
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}