#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  VEC(ll, a, 3);
  sort(a);
  Yes((a[0] == a[1] and a[1] != a[2]) or (a[1] == a[2] and a[0] != a[1]));
}
#include "MeIoN_Lib/Z_H/main.hpp"