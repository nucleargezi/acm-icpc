#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

void before() {}

// #define tests
constexpr array<char, 30> bas{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
template <typename E>
struct mono {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    X res = bas;
    FOR(i, 30) {
      if (x[i] == -1) {
        res[i] = y[i];
        continue;
      }
      if (y[i] == -1) {
        res[i] = x[i];
        continue;
      }
      if (x[i] == y[i]) res[i] = x[i];
      else res[i] = 2;
    }
    iroha res;
  }
  static constexpr X unit() { iroha bas; }
  static constexpr bool commute = true;
};
void Yorisou() {
  INT(L, n, q);
  meion f = [&](const vector<int> &v) -> array<char, 30> {
    array<char, 30> res = bas;
    FOR(i, L) {
      res[i] = v[i];
    }
    iroha res;
  };
  
  vector<array<char, 30>> a(n);
  FOR(i, n) {
    SV(s, '0');
    a[i] = f(s);
  }

  Seg<mono<array<char, 30>>> seg(a);
  int ans{};
  FOR(q) {
    INT(op);
    if (op == 0) {
      INT(l, r);
      meion res = seg.prod(--l, r);
      if (qmax(res) == 2) continue;
      int s{};
      FOR(i, L) {
        s += res[i] == -1;
      }
      ans ^= 1 << s;
    } else {
      INT(x);
      SV(s, '0');
      seg.set(--x, f(s));
    }
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