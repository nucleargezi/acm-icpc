#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  LL(a, b, c, d);
  meion f = [](ll a, ll b, ll c, ll d) -> bool {
    return (b >= a - 1 and a * 2 + 2 >= b) or (d >= c - 1 and c * 2 + 2 >= d);
  };
  YES(f(a, d, b, c));
}
#include "YRS/Z_H/main.hpp"