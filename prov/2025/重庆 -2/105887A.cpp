#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  vector<int> b(a);
  int ans = 0;
  bool f = 0;
  for (int i = 1; i < n and not f; ++i) f |= not not(a[i] ^ a[i - 1]);
  while (f) {
    f = 0;
    ++ans;
    for (int i = 0; i < n; ++i) b[i] |= a[(i + ans) % n], (i and (f |= b[i] != b[i - 1]));
    for (int i = 0; i < n; ++i) a[i] = b[i];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"