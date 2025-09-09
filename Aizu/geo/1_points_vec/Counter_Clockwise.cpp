#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  P a, b, c;
  IN(a, b);
  INT(Q);
  while (Q--) {
    IN(c);
    if (segment(a, b).contains(c)) {
      UL("ON_SEGMENT");
      continue;
    }
    if (segment(a, c).contains(b)) {
      UL("ONLINE_FRONT");
      continue;
    }
    if (segment(b, c).contains(a)) {
      UL("ONLINE_BACK");
      continue;
    }
    UL(ccw(a, b, c) == 1 ? "COUNTER_CLOCKWISE" : "CLOCKWISE");
  }
}
#include "YRS/Z_H/main.hpp"