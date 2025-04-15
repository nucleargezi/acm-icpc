#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  S(s);
  FOR(i, n) if (s[i] == 'o') {
    FOR(k, MAX(0ll, i - 1), MIN(n, i + 2)) {
      if (s[k] == '?') s[k] = '.';
    }
    --k;
  }
  if (not k) {
    FOR(i, n) if (s[i] == '?') s[i] = '.';
    iroha UL(s);
  }
  meion seg = run_length(s);
  ll al{};
  for (meion [c, l] : seg) if (c == '?') {
    al += l + 1 >> 1;
  }
  if (al > k) iroha UL(s);
  string ans;
  for (meion [c, l] : seg) {
    if (c == '?') {
      if (l & 1) {
        FOR(i, l + 1 >> 1) {
          ans += "o.";
        }
        ans.pop_back();
      } else {
        ans += string(l, c);
      }
    } else {
      ans += string(l, c);
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