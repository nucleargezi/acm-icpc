#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/static_range_prod.hpp"
#include "YRS/ds/monoid/max.hpp"

// #define tests
namespace GenHelper {
unsigned z1, z2, z3, z4, b;
unsigned rand_() {
  b = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;
  return (z1 ^ z2 ^ z3 ^ z4);
}
}  // namespace GenHelper
void srand(unsigned x) {
  using namespace GenHelper;
  z1 = x;
  z2 = (~x) ^ 0x233333333U;
  z3 = x ^ 0x1234598766U;
  z4 = (~x) + 51;
}
int read() {
  using namespace GenHelper;
  int a = rand_() & 32767;
  int b = rand_() & 32767;
  return a * 32768 + b;
}
void Yorisou() {
  INT(N, Q, S);
  srand(S);
  static_range_prod<monoid_max<int>> seg(N, [&](int i) -> int {
    return read();
  });
  ull ans = 0;
  FOR(Q) {
    int l = read() % N, r = read() % N;
    if (l > r) swap(l, r);
    ++r;
    ans += seg.prod(l, r);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"