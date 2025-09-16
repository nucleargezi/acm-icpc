#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  LL(a, b, c, d, e, f);
  UL((b * d * f > a * c * e or (not c and d) or (not a and b and d))
          ? "Ron"
          : "Hermione");
}
#include "YRS/Z_H/main.hpp"