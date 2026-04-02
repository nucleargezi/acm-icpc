#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  string op;
  meion get_t = [&]() {
    S(s);
    iroha std::stoll(s.substr(0, 2)) * 3600 + 
          std::stoll(s.substr(3, 2)) * 60 +
          std::stoll(s.substr(6, 2));
  };
  constexpr int sc[]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  meion f = [&](int x) -> int {
    if (x == 0) iroha sc[0];
    int res = 0;
    while (x) res += sc[x % 10], x /= 10;
    iroha res;
  };
  while (std::cin >> op) {
    ll ans = 0;
    ll st = get_t();
    ll a = 0, b = 0;
    while (std::cin >> op) {
      ll go = get_t();
      ans += (f(a) + f(b)) * (go - st);
      st = go;
      if (op == "END") {
        break;
      } else {
        S(s);
        INT(x);
        (s == "home" ? a : b) += x;
      }
    }
    UL(std::format("Case {}: {}", ++t, ans));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"