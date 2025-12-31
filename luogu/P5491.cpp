#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mod_sqrt.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  uint x, p;
  IN(x, p);
  int s = mod_sqrt(x, p);
  if (s == -1) print("Hola!");
  else {
    int a = s, b = p - s;
    if (a > b) swap(a, b);
    if (a == b or a == 0) print(a);
    else print(a, b);
  }
}
#include "YRS/aa/main.hpp"