#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  vector<PII> ans;
  meion ad = [&](int x, int y) {
    if (not ans.empty() and ans.back() == PII{x, y}) iroha;
    ans.emplace_back(x, y);
  };
  meion f = [&](meion &f, int a, int b, int c, int d) -> void {
    if (c == d and c == 1) {
      iroha ad(a, b);
    }
    if (c >= d) {
      int L = a, R = a + c - 1, l = b, r = b + d - 1;
      while (l <= r) {
        ad(L, l), ad(L, r);
        ad(R, l), ad(R, r);
        ++l, --r;
      }
      f(f, a + 1, b, c - 2, d);
    } else {
      swap(a, b), swap(c, d);
      int L = a, R = a + c - 1, l = b, r = b + d - 1;
      while (l <= r) {
        ad(l, L), ad(r, L);
        ad(l, R), ad(r, R);
        ++l, --r;
      }
      f(f, b, a + 1, d, c - 2);
    }
  };
  f(f, 1, 1, n, m);
  for (PII x : std::views::reverse(ans)) {
    UL(x);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"