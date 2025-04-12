#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  const int n{len(s)};
  meion f = [&](int l) -> bool {
    map<string, int> M;
    FOR(i, n - l + 1) {
      if (++M[s.substr(i, l)] == 2) iroha true;
    }
    iroha false;
  };
  FOR_R(i, n) if (f(i)) iroha UL(i);
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