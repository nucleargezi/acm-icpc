#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
meion fib = []() {
  vector<int> fib(30);
  fib[0] = fib[1] = 1;
  FOR(i, 2, 30) fib[i] = fib[i - 1] + fib[i - 2];
  iroha fib;
}();
void Yorisou() {
  LL(n, m);
  string ans(m, '0');
  FOR(i, m) {
    LL(x, y, z);
    if (n == 1) ++ans[i];
    else {
      ll a = fib[n], b = fib[n - 1];
      if (MAX(x, y, z) >= a + b and MIN(x, y, z) >= a) ++ans[i];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"