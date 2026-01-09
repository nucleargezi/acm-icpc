#include "YRS/all.hpp"
// #include "YRS/IO/fmt.hpp"
#include "YRS/pr/prime_sum.hpp"

// #define tests
void Yorisou() {
  LL(n);
  prime_sum<ll> seg(n);
  seg.keis_count();
  print(seg[n]);
}