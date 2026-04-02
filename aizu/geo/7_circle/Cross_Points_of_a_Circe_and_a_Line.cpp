#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  circle<RE> C;
  IN(C.O, C.R);
  INT(Q);
  setp(8);
  while (Q--) {
    P s, t;
    IN(s, t);
    meion ans = C.cross_point(line(s, t));
    if (len(ans) == 1) ans.emplace_back(ans[0]);
    sort(ans);
    UL(ans);
  }
}
#include "YRS/Z_H/main.hpp"