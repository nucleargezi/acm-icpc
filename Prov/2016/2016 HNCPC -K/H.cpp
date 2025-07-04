#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  int n;
  string s;
  constexpr int N = 2'000'00;
  vector pw = power_table_1(mint(10), N);
  vector ips = pre_sum<false>(power_table_1(mint(10).inv(), N));
  FOR(i, N + 1) ips[i] -= 1;

  while (IN(n, s)) {
    vector a = s_to_vec<int>(s, '0');
    mint ans;
    FOR(i, n) if (a[i]) {
      mint ap = i * (i + 1) / 2 + (n - i) * (n - i - 1) / 2;
      ap *= pw[n - i - 1];
      mint A = ips[i + 1], B = ips[n] - ips[i];
      ans += (ap + A * B * pw[n + i + 1]) * a[i];
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"