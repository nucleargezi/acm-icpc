#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  REAL(a, b);
  b *= 4;
  RE ans;
  if (b == 0) ans = 1;
  else if (a == 0) ans = 0.5;
  else if (a < b) ans = (a + b * 2) * a / a / b / 4;
  else ans = (a * b + (a * 2 - b) * b / 2) / (a * b * 2);
  setp(10); 
  print(ans);
}
#include "YRS/Z_H/main.hpp"