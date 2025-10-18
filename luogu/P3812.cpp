#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/line/01/xor_vector_space.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  vector_space<ll> s;
  FOR(n) {
    LL(x);
    s.add(x);
  }
  UL(s.get_max());
}
#include "MeIoN_Lib/Z_H/main.hpp"