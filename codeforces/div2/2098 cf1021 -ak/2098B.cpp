#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  VEC(int, a, n);
  sort(a);
  int sz = n - k;
  int l = a[sz - 1 >> 1], r = a[k + (sz >> 1)];
  print("{}", r - l + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"