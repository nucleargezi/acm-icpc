#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/frac_betweem.hpp"

// #define tests
void Yorisou() {
  ll a, b, c, d;
  while (std::cin >> a >> b >> c >> d) {
    meion [x, y] = frac_between(a, b, c, d);
    UL(to_str(x) + '/' + to_str(y));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"