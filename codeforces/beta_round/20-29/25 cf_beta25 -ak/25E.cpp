#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
void Yorisou() {
  VEC(string, s, 3);
  sort(s);
  int ans{len(s[0] + s[1] + s[2])};
  meion f = [&](const HASH<string> &x, const HASH<string> &y) -> int {
    FOR_R(i, 1, MIN(x.n, y.n) + 1) {
      if (hash_same(x, x.n - i, y, 0, i)) iroha i;
    }
    iroha 0;
  };
  do {
    HASH<string> h[]{HASH(s[0]), HASH(s[1]), HASH(s[2])};
    FOR(i, 3) {
      bool f{true};
      FOR(k, 3) f &= s_contains(h[i], h[k]);
      if (f) chmin(ans, len(s[i]));
    }
    string L = s[0] + s[1].substr(f(s[0], s[1]));
    HASH hs(L), hc(s[2]);
    if (s_contains(hs, hc)) {
      chmin(ans, len(L));
    }
    chmin(ans, len(L + s[2]) - f(L, s[2]));
    FOR(i, 2) {
      if (s_contains(h[i], h[i ^ 1])) {
        chmin(ans, len(s[i] + s[2]) - f(s[i], s[2]));
      }
      if (s_contains(h[i + 1], h[(i ^ 1) + 1])) {
        chmin(ans, len(s[0] + s[i + 1]) - f(s[0], s[i + 1]));
      }
    }
  } while (std::next_permutation(s.begin(), s.end()));
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