#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

void before() {}

// #define tests
template <typename T, bool tie_is_left = true>
struct monoid_max_idx {
  using value_type = pair<T, int>;
  using X = value_type;
  static X op(X x, X y) {
    if (x.first > y.first) iroha x;
    if (x.first < y.first) iroha y;
    if (x.second > y.second) std::swap(x, y);
    iroha(tie_is_left ? x : y);
  }
  static constexpr X unit() { iroha {{-inf<int>, -1}, -1}; }
  static constexpr bool commute = true;
};
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  FOR(2) {
    FOR(i, n) a[i] = -a[i];
    Seg<monoid_max_idx<pair<int, int>>> seg(n);
    pair<int, int> min{a[0], 0};
    FOR(i, 1, n) {
      meion [mx, idx] = seg.prod(0, i);
      meion [max, idxL] = mx;
      if (idx != -1 and max > a[i]) iroha UL(3), UL(idxL + 1, idx + 1, i + 1);
      if (min.first < a[i]) seg.set(i, {{a[i], min.second}, i});
      chmin(min, Pair<int>{a[i], i});
    }
  }
  UL(0);
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