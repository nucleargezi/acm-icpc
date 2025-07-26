#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(a, b, k);
  ll g = std::gcd(a, b);
  a /= g, b /= g;
  UL(1 + (MAX(a, b) > k));
}
#include "MeIoN_Lib/Z_H/main.hpp"