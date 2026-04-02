#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mint = M17;
int T;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  LL(K);
  int mn = inf<int>;
  mint ans;
  for (int i = 0, a = 0; a <= K; a += i * 3 + 1, ++i) {
    int j = 0, c = 0;
    while (a + c + j * 3 + 3 <= K) c += j * 3 + 3, ++j;
    for (int k = 0, b = 0; a + b <= K; b += k * 3 + 2, ++k) {
      while (a + b + c > K) --j, c -= j * 3 + 3;
      if (a + b + c == K) {
        chmin(mn, i + k + j);
        ans += fact<mint>(i + k + j) * fact_inv<mint>(i) * 
               fact_inv<mint>(k) * fact_inv<mint>(j);
      }
    }
  }
  print(mn, ans);
}
#include "YRS/Z_H/main.hpp"