#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  int n = len(s);
  FOR(i, n) {
    FOR(c, 'a', 'z' + 1) {
      meion r = s.substr(0, i) + char(c) + s.substr(i);
      meion l = r;
      reverse(l);
      if (l == r) iroha UL(r);
    }
  }
  FOR(c, 'a', 'z' + 1) {
    s += char(c);
    meion t = s;
    reverse(t);
    if (s == t) iroha UL(s);
    s.pop_back();
  }
  UL("NA");
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