#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  P s, t;
  IN(s, t);
  line L(s, t);
  INT(Q);
  setp(10);
  while (Q--) {
    P p;
    IN(p);
    UL(L.reflection(p));
  }
}
#include "YRS/Z_H/main.hpp"