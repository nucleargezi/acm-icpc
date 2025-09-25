#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"

// #define tests
ull hash(ull x, ull y) {
  return x << 30 | y;
}
void Yorisou() {
  LL(X, Y, W);
  Z rev = [&](int x) -> int {
    int r = 0;
    while (x) r = r * 10 + x % 10, x /= 10;
    return r;
  };
  int x = -1, y = -1;
  Z check = [&](ll m) -> bool {
    hash_map<int> mp, ma;
    FOR(b, 1, Y + 1) {
      int r = rev(b);
      int g = std::gcd(r, b);
      ++mp[hash(r / g, b / g)];
    }
    ll s = 0;
    int b = Y;
    FOR(a, 1, X + 1) {
      while (1ll * a * b > m) {
        int r = rev(b), g = std::gcd(r, b);
        s -= ma.get(hash(r / g, b / g), 0);
        --mp[hash(r / g, b / g)];
        --b;
      }
      int r = rev(a), g = std::gcd(r, a);
      ++ma[hash(a / g, r / g)];
      s += mp.get(hash(a / g, r / g), 0);
      if (s >= W) {
        x = a, y = b;
        return true;
      }
    }
    return false;
  };
  check(binary_search<false>(check, X * Y, -1));
  if (x == -1) return print(-1);
  print(x, y);
}
#include "YRS/Z_H/main.hpp"