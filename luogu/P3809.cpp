#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SA.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
void Yorisou() {
  STR(s);
  SA seg(s);
  for (int &x : seg.sa) ++x;
  print(seg.sa);
}
#include "YRS/Z_H/main.hpp"