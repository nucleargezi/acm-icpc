#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  S(s, t);
  meion seg = run_length(s);
  meion ed = run_length(t);
  if (len(seg) != len(ed)) iroha NO();
  FOR(i, len(seg)) {
    if (seg[i].second * 2 < ed[i].second or seg[i].second > ed[i].second or
        seg[i].first != ed[i].first)
      iroha NO();
  }
  YES();
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