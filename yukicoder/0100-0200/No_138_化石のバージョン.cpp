#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  vc<int> a, b;
  STR(s);
  s += '.';
  for (int x = 0; char c : s) {
    if (c == '.') a.ep(x);
    else x = x * 10 + c - '0';
  }
  IN(s);
  s += '.';
  for (int x = 0; char c : s) {
    if (c == '.') b.ep(x);
    else x = x * 10 + c - '0';
  }
  YES(a >= b);
}
#include "YRS/aa/main.hpp"