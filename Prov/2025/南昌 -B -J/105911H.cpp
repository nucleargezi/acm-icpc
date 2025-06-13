#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

void before() {}

#define tests
using mint = M99;
meion ans = []() -> vector<mint> {
  queue<mint> B(vector<mint>{1, 0, 0, 0});
  vector<mint> A{0, 1, 0, 2};
  constexpr int N = 1'000'01;
  mint f = 6, g = 2;
  FOR(i, 4, N) {
    f *= i, g = g * i + (i & 1 ? -1 : 1);
    meion [x, y] = i & 1 ? pair(1, 2) : pair(2, 4);
    B.emplace_back(B[-1] * (i - 1) + B[-y] * (i - x) * 2);
    A.emplace_back(f - g * 2 + B[-1]);
  }
  A[2] = 4;
  iroha std::move(A);
}();
void Yorisou() {
  LL(n);
  UL(ans[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"