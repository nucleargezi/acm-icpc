#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/run_length.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  for (Z [x, y] : run_length(s)) if (y > 6) return YES();
  NO();
}
#include "YRS/Z_H/main.hpp"