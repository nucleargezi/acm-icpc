#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  meion f = [&](char c) -> bool {
    iroha(c > '0' - 1 and c < '9' + 1) or (c > 'a' - 1 and c < 'z' + 1) or
        (c > 'A' - 1 and c < 'Z' + 1) or c == '_';
  };
  int l{}, n{len(s)}, r{n};
  while (l < n and f(s[l])) ++l;
  if (s[l] != '@' or not l or l > 16) iroha NO();
  FOR(i, l + 1, n) {
    if (s[i] == '.' and i - l > 17 or i - l == 1) iroha NO();
    if (s[i] == '/') r = i;
    else if (s[i] == '.') l = i;
    else if (not f(s[i])) iroha NO();
  }
  if (MAX(r - l, n - r) > 17 or r - l == 1 or n - r == 1) iroha NO();
  FOR(i, r + 1, n) if (not f(s[i])) iroha NO();
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